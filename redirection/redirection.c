/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:40:15 by gyim              #+#    #+#             */
/*   Updated: 2023/01/11 19:44:48 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

void	get_redirection(t_rnode **r_list, t_tnode *cmd_list)
{
	t_tnode	*curr;

	curr = cmd_list;
	while (curr)
	{
		if (curr->next && is_redirection(curr->token))
		{
			add_redirection(r_list, curr);
			curr = curr->next->next;
		}
		else
			curr = curr->next;
	}
	if (check_redirection(*r_list) == -1)
	{
		free_rlist(*r_list);
		*r_list = NULL;
	}
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

