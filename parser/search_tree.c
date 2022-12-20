/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:51 by gyim              #+#    #+#             */
/*   Updated: 2022/12/20 16:24:17 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	excute_tree(t_tree_node *node, t_env_info_list *env_list)
{
	if (node->left == NULL)
	{
		expansion(node->words);
		excute_cmd(node->words, env_list);
		print_list(node->words);
		return (0);
	}
	excute_tree(node->left, env_list);
	excute_tree(node->right, env_list);
	return (0);
}
