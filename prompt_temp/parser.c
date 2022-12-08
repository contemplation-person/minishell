/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:21:32 by gyim              #+#    #+#             */
/*   Updated: 2022/12/08 10:58:31 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "split_input.h"

t_node	*parser(t_tlist_info *list)
{
	int		len;
	char	**init_cmds;
	t_node	*root;

	init_cmds = get_cmds_from_list(list);
	root = make_tree(init_cmds);
	if (!root)
		return (NULL);
	return (root);
}

char	**get_cmds_from_list(t_tlist_info *list)
{
	int		len;
	char	**cmds;

	len = list_len(list);
	cmds = malloc(sizeof(char *) * (len + 1));
	cmds[len] = NULL;
	copy_from_list(cmds, list);
	return (cmds);
}

int	list_len(t_tlist_info *list)
{
	int		len;
	t_tnode	*node;

	len = 0;
	node = list->head;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
}

void	copy_from_list(char **target, t_tlist_info *list)
{
	t_tnode	*curr;
	int		target_index;

	target_index = 0;
	curr = list->head;
	while (curr)
	{
		target[target_index] = ft_strdup(curr->token);
		target_index++;
		curr = curr->next;
	}
}
