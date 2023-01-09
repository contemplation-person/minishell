/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:42:25 by gyim              #+#    #+#             */
/*   Updated: 2023/01/09 09:41:46 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	op_pipe(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		fd[2];
	t_fds	child_fds[2];
	int		pid;

	pipe(fd);
	child_fds[0].in_fd = fd_info->in_fd;
	child_fds[0].out_fd = fd[1];
	child_fds[1].in_fd = fd[0];
	child_fds[1].out_fd = fd_info->out_fd;
	pid = op_pipe_left_excute(node, &child_fds[0], fd, env_list);
	pid = op_pipe_right_excute(node, &child_fds[1], fd, env_list);
	close(fd[1]);
	close(fd[0]);
	close(fd_info->in_fd);
	close(fd_info->out_fd);
	return (pid);
}

int	op_pipe_left_excute(t_tree_node *node, t_fds *fd_info, int pipe_fd[2],
			t_env_info_list *env_list)
{
	int	pid;

	if (!node->left->words)
		pid = pipe_search_tree(node->left, fd_info, env_list);
	else
		pid = pipe_excute_leaf(node->left->words, fd_info, env_list);
	close(pipe_fd[1]);
	return (pid);
}

int	op_pipe_right_excute(t_tree_node *node, t_fds *fd_info, int pipe_fd[2],
			t_env_info_list *env_list)
{
	int	pid;

	if (!node->right->words)
		pid = pipe_search_tree(node->right, fd_info, env_list);
	else
		pid = pipe_excute_leaf(node->right->words, fd_info, env_list);
	close(pipe_fd[0]);
	return (pid);
}
