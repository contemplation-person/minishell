/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:53:14 by gyim              #+#    #+#             */
/*   Updated: 2023/01/05 10:25:16 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	check_redirection(t_rnode *head)
{
	t_rnode	*curr;

	curr = head;
	while (curr)
	{
		if (is_redirection(curr->file))
		{
			write(2, "unexpected token near \'", 23);
			write(2, curr->file, ft_strlen(curr->file));
			write(2, "'\n", 2);
			g_error_code = 2;
			return (-1);
		}
		curr = curr->next;
	}
	return (0);
}

void	free_rlist(t_rnode *head)
{
	t_rnode	*curr;
	t_rnode	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr->file);
		free(curr);
		curr = next;
	}
}

int	renewal_fds(t_rnode *node, t_fds *fds, t_env_info_list *envp_list)
{
	if (node->redirection == 1)
		return (set_outfile(fds, node));
	else if (node->redirection == 2)
		return (set_addfile(fds, node));
	else if (node->redirection == 3)
		return (set_infile(fds, node));
	else if (node->redirection == 4)
		return (set_here_doc(node, envp_list));
	return (-1);
}

int	set_fds(t_fds *fds, t_rnode *node, t_env_info_list *envp_list)
{
	t_rnode	*curr;
	t_fds	temp;

	temp.in_fd = -1;
	temp.out_fd = -1;
	curr = node;
	while (curr)
	{
		if (renewal_fds(curr, &temp, envp_list) == -1)
			return (-1);
		curr = curr->next;
	}
	change_fds(fds, &temp);
	return (0);
}
