/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:21:32 by gyim              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/27 15:07:09 by juha             ###   ########seoul.kr  */
=======
/*   Updated: 2022/12/27 18:38:19 by gyim             ###   ########seoul.kr  */
>>>>>>> 8a500e446c1d86948b092176219bad682b47233a
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
	print_list(word_list->head);
	if (valid_check(word_list->head) == -1)
	{
		del_list(word_list);
		return (0);
	}
	// if (multiple_cmds_check(word_list) == 0)
	// 	one_cmd_excute(word_list, env_list);
	// else
	multiple_cmds_excute(word_list, env_list);
	free(word_list);
	word_list = NULL;
	return (0);
}
