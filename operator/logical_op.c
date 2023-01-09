/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:27:35 by gyim              #+#    #+#             */
/*   Updated: 2023/01/09 10:28:43 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	op_double_and(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		pid;
	int		status;
	t_fds	second;

	pid = search_tree(node->left, fd_info, env_list);
	waitpid(pid, &status, 0);
	g_error_code = WEXITSTATUS(status);
	dup2(second.in_fd, fd_info->stdin_fd);
	dup2(second.out_fd, fd_info->stdout_fd);
	if (g_error_code == 0)
		pid = search_tree(node->right, &second, env_list);
	else
		pid = -999;
	close(second.in_fd);
	close(second.out_fd);
	return (pid);
}

int	op_double_or(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		pid;
	int		status;
	t_fds	second;

	pid = search_tree(node->left, fd_info, env_list);
	waitpid(pid, &status, 0);
	g_error_code = WEXITSTATUS(status);
	dup2(second.in_fd, fd_info->stdin_fd);
	dup2(second.out_fd, fd_info->stdout_fd);
	g_error_code = WEXITSTATUS(status);
	if (g_error_code != 0)
		pid = search_tree(node->right, &second, env_list);
	else
		pid = -999;
	close(second.in_fd);
	close(second.out_fd);
	return (pid);
}
