/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:51 by gyim              #+#    #+#             */
/*   Updated: 2022/12/30 17:59:07 by juha             ###   ########seoul.kr  */
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
			op_pipe(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, "<", 2) == 0)
			op_infile(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, ">", 2) == 0)
			op_outfile(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, ">>", 3) == 0)
			op_append(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, "<<", 3) == 0)
			op_here_doc(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, "&&", 3) == 0)
			op_double_and(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, "||", 3) == 0)
			op_double_or(node, fd_info, env_list);
		else
			return (-1);
	}
	else
	{
		excute_leaf(node->words, fd_info, env_list);
	}
	return (0);
}
