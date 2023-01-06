/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:51 by gyim              #+#    #+#             */
/*   Updated: 2023/01/06 17:24:54 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	tree_valid_check(t_tree_node *node)
{
	if (node->op != NULL)
	{
		if (node->left == NULL || node->right == NULL)
		{
			write(2, "error near operator\n", 20);
			g_error_code = 2;
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
		if (ft_strncmp(node->op->token, "|", 2) == 0)
			return (op_pipe(node, fd_info, env_list));
		else if (ft_strncmp(node->op->token, "&&", 3) == 0)
			return (op_double_and(node, fd_info, env_list));
		else if (ft_strncmp(node->op->token, "||", 3) == 0)
			return (op_double_or(node, fd_info, env_list));
		else
			return (-1);
	}
	else
		excute_leaf(node->words, fd_info, env_list);
	return (0);
}
