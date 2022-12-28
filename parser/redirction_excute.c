/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirction_excute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:58:17 by gyim              #+#    #+#             */
/*   Updated: 2022/12/28 10:17:46 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	op_infile(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int		infile_fd;
	int		fd[2];
	pid_t	pid;

	infile_fd = open(node->right->words->token, O_RDONLY);

	pid = fork();
	if (pid == 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		dup2(fd_info->out_fd, STDOUT_FILENO);
		
	}
}

int	op_outfile(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{

}