/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:51 by gyim              #+#    #+#             */
/*   Updated: 2022/12/22 17:44:09 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	excute_tree(t_tree_node *node, t_env_info_list *env_list)
{
	if (node->op != NULL)
	{
		if (node->left == NULL || node->right == NULL)
		{
			write(2, "error near operator\n", 20);
			return (-1);
		}
		if (excute_tree(node->left, env_list) == -1
			|| excute_tree(node->right, env_list) == -1)
			return (-1);
	}
	else
	{
		expansion(node->words);
		excute_leaf(node->words, env_list);
		print_list(node->words);
	}
	return (0);
}
