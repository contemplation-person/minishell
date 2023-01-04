/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:37:37 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 11:29:09 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	set_outfile(t_fds *fds, t_rnode *node)
{
	int	outfile;

	if (fds->out_fd != -1)
		close(fds->out_fd);
	outfile = open(node->file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (outfile < 0)
	{
		write(2, "Permission denied\n", 18);
		g_error_code = 1;
		return (-1);
	}
	fds->out_fd = outfile;
	return (0);
}

int	set_addfile(t_fds *fds, t_rnode *node)
{
	int	addfile;

	if (fds->out_fd != -1)
		close(fds->out_fd);
	addfile = open(node->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (addfile < 0)
	{
		write(2, "Permission denied\n", 18);
		g_error_code = 1;
		return (-1);
	}
	fds->out_fd = addfile;
	return (0);
}

int	set_infile(t_fds *fds, t_rnode *node)
{
	int	infile;
	int	code;

	if (fds->in_fd != -1)
		close(fds->in_fd);
	code = access(node->file, F_OK);
	if (code == -1)
	{
		write(2, NO_FILE_DIR, ft_strlen(NO_FILE_DIR));
		g_error_code = 1;
		return (-1);
	}
	infile = open(node->file, O_RDONLY);
	if (infile < 0)
	{
		write(2, "Permission denied\n", 18);
		g_error_code = 1;
		return (-1);
	}
	fds->in_fd = infile;
	return (0);
}

int	set_here_doc(t_rnode *node)
{
	int	here_doc_fd;

	here_doc_fd = open(HERE_DOC_NAME, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (here_doc_fd == -1)
	{
		write(2, "Permission denied\n", 18);
		g_error_code = 1;
		return (-1);
	}
	read_lines(here_doc_fd, node->file);
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
