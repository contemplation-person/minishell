/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:41:54 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 19:42:07 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	del_tree(t_tree_node *node)
{	
	if (node->left != NULL)
	{
		del_tree(node->left);
		free(node->left);
	}
	if (node->right != NULL)
	{
		del_tree(node->right);
		free(node->right);
	}
	del_sublist(node->op);
	del_sublist(node->words);
}
