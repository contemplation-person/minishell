/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:21:32 by gyim              #+#    #+#             */
/*   Updated: 2022/12/30 17:58:58 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree_node	*parser(t_tlist_info *list)
{
	t_tree_node	*root;

	root = make_tree(list->head);
	if (!root)
		return (NULL);
	return (root);
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

int	parsing_excute(char *user_input, t_env_info_list *env_list)
{
	t_tlist_info	*word_list;

	if (user_input[0] == '\0')
		return (0);
	word_list = split_input(user_input);
	if (valid_check(word_list->head) == -1)
	{
		del_list(word_list);
		return (0);
	}
	multiple_cmds_excute(word_list, env_list);
	free(word_list);
	word_list = NULL;
	return (0);
}
