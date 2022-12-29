/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_excute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:58:17 by gyim              #+#    #+#             */
/*   Updated: 2022/12/29 11:41:20 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	op_infile(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		infile_fd;
	t_fds	cmd_fds;

	infile_fd = open(node->right->words->token, O_RDONLY);
	cmd_fds.in_fd = infile_fd;
	cmd_fds.out_fd = fd_info->out_fd;
	excute_leaf(node->left->words, &cmd_fds, env_list);
	close(infile_fd);
	return (0);
}

int	op_outfile(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		outfile_fd;
	t_fds	cmd_fds;

	outfile_fd = open(node->right->words->token,
			O_TRUNC | O_WRONLY | O_CREAT, 0644);
	cmd_fds.in_fd = fd_info->in_fd;
	cmd_fds.out_fd = outfile_fd;
	excute_leaf(node->left->words, &cmd_fds, env_list);
	close(outfile_fd);
	return (0);
}

int	op_append(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		outfile_fd;
	t_fds	cmd_fds;

	outfile_fd = open(node->right->words->token,
			O_CREAT | O_WRONLY | O_APPEND, 0644);
	cmd_fds.in_fd = fd_info->in_fd;
	cmd_fds.out_fd = outfile_fd;
	excute_leaf(node->left->words, &cmd_fds, env_list);
	close(outfile_fd);
	return (0);
}

int	op_here_doc(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		fd[2];
	char	*limiter;
	t_fds	cmd_fds;

	limiter = node->right->words->token;
	pipe(fd);
	cmd_fds.in_fd = fd[0];
	cmd_fds.out_fd = fd_info->out_fd;
	read_lines(limiter, fd);
	close(fd[1]);
	excute_leaf(node->left->words, &cmd_fds, env_list);
	close(fd[0]);
	return (0);
}