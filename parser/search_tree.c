/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:51 by gyim              #+#    #+#             */
/*   Updated: 2022/12/25 13:43:50 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	excute_tree(t_tree_node *node, t_env_info_list *env_list)
{
	return (0);
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

int	tree_valid_check(t_tree_node *node)
{
	if (node->op != NULL)
	{
		print_list(node->op);
		if (node->left == NULL || node->right == NULL)
		{
			write(2, "error near operator\n", 20);
			return (-1);
		}
		if (tree_valid_check(node->left) == -1)
			return (-1);
		if (tree_valid_check(node->right) == -1)
			return (-1);
	}
	return (0);
}

int	search_tree(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	if (node->op != NULL)
	{
		if (node->op->token[0] == '|')
			op_pipe(node, fd_info, env_list);
	}
	else
	{
		excute_cmd(node->words, env_list);
	}
}
