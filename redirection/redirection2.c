/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:37:37 by gyim              #+#    #+#             */
/*   Updated: 2023/01/17 16:12:49 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	set_outfile(t_rnode *node)
{
	int	outfile;

	outfile = open(node->file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (outfile < 0)
	{
		write(2, "Permission denied\n", 18);
		g_error_code = 1;
		return (1);
	}
	close(STDOUT_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	return (0);
}

int	set_addfile(t_rnode *node)
{
	int	addfile;

	addfile = open(node->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (addfile < 0)
	{
		write(2, "Permission denied\n", 18);
		g_error_code = 1;
		return (1);
	}
	close(STDOUT_FILENO);
	dup2(addfile, STDOUT_FILENO);
	close(addfile);
	return (0);
}

int	set_infile(t_rnode *node)
{
	int	infile;
	int	code;

	code = access(node->file, F_OK);
	if (code == -1)
	{
		write(2, NO_FILE_DIR, ft_strlen(NO_FILE_DIR));
		g_error_code = 1;
		return (1);
	}
	infile = open(node->file, O_RDONLY);
	if (infile < 0)
	{
		write(2, "Permission denied\n", 18);
		g_error_code = 1;
		return (1);
	}
	close(STDIN_FILENO);
	dup2(infile, STDIN_FILENO);
	close(infile);
	return (0);
}

int	set_here_doc(t_rnode *node)
{
	int		here_doc_fd;

	here_doc_fd = open(node->file, O_RDONLY, 0644);
	if (here_doc_fd == -1)
	{
		g_error_code = 1;
		return (1);
	}
	unlink(node->file);
	close(STDIN_FILENO);
	dup2(here_doc_fd, STDIN_FILENO);
	close(here_doc_fd);
	return (0);
}

void	free_red(t_rnode *rd_head)
{
	t_rnode	*curr;
	t_rnode	*next;

	curr = rd_head;
	while (curr)
	{
		next = curr->next;
		free(curr->file);
		free(curr);
		curr = next;
	}
}
