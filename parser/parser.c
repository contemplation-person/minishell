/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:21:32 by gyim              #+#    #+#             */
/*   Updated: 2022/12/19 14:57:33 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree_node	*parser(t_tlist_info *list)
{
	int			len;
	char		**init_cmds;
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

int	parsing_excute(char *user_input)
{
	t_tlist_info	*word_list;
	t_tree_node		*root;

	if (user_input[0] == '\0')
		return (0);
	if (ft_strncmp(user_input, "exit", 5) == 0)
		return (-1);
	word_list = split_input(user_input);
	print_list(word_list->head);
	if (valid_check(word_list->head) == -1)
	{
		del_list(word_list);
		return (0);
	}
	root = parser(word_list);
	excute_tree(root);
	del_list(word_list);
	del_tree(root);
	free(root);
	word_list = NULL;
	return (0);
}
