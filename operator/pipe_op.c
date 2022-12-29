/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:42:25 by gyim              #+#    #+#             */
/*   Updated: 2022/12/29 19:46:53 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	op_pipe(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		fd[2];
	t_fds	child_fds[2];

	pipe(fd);
	child_fds[0].in_fd = fd_info->in_fd;
	child_fds[0].out_fd = fd[1];
	child_fds[1].in_fd = fd[0];
	child_fds[1].out_fd = fd_info->out_fd;
	op_pipe_left_excute(node, &child_fds[0], fd, env_list);
	op_pipe_right_excute(node, &child_fds[1], fd, env_list);
	close(fd[0]);
	close(fd[1]);
	wait(0);
	return (0);
}

int	op_pipe_left_excute(t_tree_node *node, t_fds *fd_info, int fd[2],
			t_env_info_list *env_list)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		search_tree(node->left, fd_info, env_list);
		close(fd[1]);
		exit(0);
	}
	return (0);
}

int	op_pipe_right_excute(t_tree_node *node, t_fds *fd_info, int fd[2],
			t_env_info_list *env_list)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		search_tree(node->right, fd_info, env_list);
		close(fd[0]);
		exit(0);
	}
	return (0);
}
