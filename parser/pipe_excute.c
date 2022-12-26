/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_excute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:42:25 by gyim              #+#    #+#             */
/*   Updated: 2022/12/26 14:24:17 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	op_pipe(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	pid_t	pid[2];
	int		fd[2];
	t_fds	child_fds[2];

	pipe(fd);
	child_fds[0].in_fd = fd_info->in_fd;
	child_fds[0].out_fd = fd[1];
	child_fds[1].in_fd = fd[0];
	child_fds[1].out_fd = fd_info->out_fd;
	pid[0] = fork();
	if (pid[0] == 0)
	{
		close(fd[0]);
		search_tree(node->left, &child_fds[0], env_list);
		exit(0);
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		close(fd[1]);
		search_tree(node->right, &child_fds[1], env_list);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
