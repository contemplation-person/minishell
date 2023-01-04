/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:40:15 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 18:59:52 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

t_rnode	*get_redirection(t_tnode *cmd_list)
{
	t_tnode	*curr;
	t_rnode	*rd_head;

	rd_head = NULL;
	curr = cmd_list;
	while (curr)
	{
		if (curr->next && is_redirection(curr->token))
		{
			add_redirection(&rd_head, curr);
			curr = curr->next->next;
		}
		else
			curr = curr->next;
	}
	if (check_redirection(rd_head) == -1)
	{
		free_rlist(rd_head);
		rd_head = NULL;
	}
	return (rd_head);
}

int	is_redirection(char *token)
{
	if (!ft_strncmp(token, ">", 2))
		return (1);
	else if (!ft_strncmp(token, ">>", 3))
		return (1);
	else if (!ft_strncmp(token, "<", 2))
		return (1);
	else if (!ft_strncmp(token, "<<", 3))
		return (1);
	return (0);
}

void	add_redirection(t_rnode	**r_list, t_tnode *node)
{
	t_rnode	*new_node;
	t_rnode	*last;

	new_node = set_redirection(node);
	if (!*r_list)
		*r_list = new_node;
	else
	{
		last = *r_list;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
}

t_rnode	*set_redirection(t_tnode *node)
{
	t_rnode	*new_node;

	new_node = malloc(sizeof(t_rnode));
	new_node->next = NULL;
	if (!ft_strncmp(node->token, ">", 2))
		new_node->redirection = 1;
	else if (!ft_strncmp(node->token, ">>", 3))
		new_node->redirection = 2;
	else if (!ft_strncmp(node->token, "<", 2))
		new_node->redirection = 3;
	else if (!ft_strncmp(node->token, "<<", 3))
		new_node->redirection = 4;
	new_node->file = ft_strdup(node->next->token);
	return (new_node);
}

int	set_fds(t_fds *fds, t_rnode *node)
{
	int		ret;
	t_rnode	*curr;
	t_fds	temp;

	temp.in_fd = -1;
	temp.out_fd = -1;
	curr = node;
	while (curr)
	{
		if (curr->redirection == 1)
			ret = set_outfile(&temp, curr);
		else if (curr->redirection == 2)
			ret = set_addfile(&temp, curr);
		else if (curr->redirection == 3)
			ret = set_infile(&temp, curr);
		else if (curr->redirection == 4)
			ret = set_here_doc(curr);
		if (ret == -1)
			return (-1);
		curr = curr->next;
	}
	if (temp.in_fd != -1)
	{
		if (fds->in_fd > 0)
			close(fds->in_fd);
		fds->in_fd = temp.in_fd;
	}
	if (temp.out_fd != -1)
	{
		if (fds->out_fd > 0)
			close(fds->out_fd);
		fds->out_fd = temp.out_fd;
	}
	if (access(HERE_DOC_NAME, F_OK) == 0)
		fds->in_fd = open(HERE_DOC_NAME, O_RDONLY);
	return (0);
}
