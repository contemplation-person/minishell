/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:37:37 by gyim              #+#    #+#             */
/*   Updated: 2023/01/03 14:27:18 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

int	set_outfile(t_fds *fds, t_rnode *node)
{
	int	outfile;

	outfile = open(node->file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (outfile < 0)
	{
		write(2, "Permission denied\n", 18);
		return (-1);
	}
	fds->out_fd = outfile;
	return (0);
}

int	set_addfile(t_fds *fds, t_rnode *node)
{
	int	addfile;

	addfile = open(node->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (addfile < 0)
	{
		write(2, "Permission denied\n", 18);
		return (-1);
	}
	fds->out_fd = addfile;
	return (0);
}

int	set_infile(t_fds *fds, t_rnode *node)
{
	int	infile;

	infile = open(node->file, O_RDONLY);
	if (infile < 0)
	{
		write(2, "Permission denied\n", 18);
		return (-1);
	}
	fds->in_fd = infile;
	return (0);
}

int	set_here_doc(t_fds *fds, t_rnode *node)
{
	int	infile;

	infile = open(node->file, O_RDONLY);
	if (infile < 0)
	{
		write(2, "Permission denied\n", 18);
		return (-1);
	}
	fds->in_fd = infile;
	return (0);
}
