/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:27:35 by gyim              #+#    #+#             */
/*   Updated: 2023/01/08 22:48:21 by gyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	op_double_and(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int	pid;
	int	status;

	pid = search_tree(node->left, fd_info, env_list);
	waitpid(pid, &status, 0);
	g_error_code = WEXITSTATUS(status);
	printf("error : %d\n", g_error_code);
	if (g_error_code == 0)
		pid = search_tree(node->right, fd_info, env_list);
	return (pid);
}

int	op_double_or(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int	pid;
	int	status;

	pid = search_tree(node->left, fd_info, env_list);
	waitpid(pid, &status, 0);
	g_error_code = WEXITSTATUS(status);
	if (g_error_code != 0)
		pid = search_tree(node->right, fd_info, env_list);
	return (pid);
}
