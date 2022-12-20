/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:04:30 by gyim              #+#    #+#             */
/*   Updated: 2022/12/19 11:10:51 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree_node	*make_tree(t_tnode *head)
{
	t_tnode		*op_node;
	t_tree_node	*new_node;

	head = delete_paren(head);
	op_node = find_op(head);
	new_node = make_new_node();
	if (!new_node)
		return (NULL);
	if (!op_node)
	{
		new_node->words = head;
		return (new_node);
	}
	if (make_child(new_node, head, op_node) == -1)
		return (NULL);
	else
		return (new_node);
}

t_tree_node	*make_new_node(void)
{
	t_tree_node	*new_node;

	new_node = malloc(sizeof(t_tree_node));
	if (!new_node)
		return (NULL);
	new_node->op = NULL;
	new_node->words = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

int	make_child(t_tree_node *parent_node, t_tnode *head, t_tnode *op_node)
{
	t_tnode	*l_cmds;
	t_tnode	*r_cmds;
	t_tnode	*op_node_prev;

	l_cmds = head;
	r_cmds = op_node->next;
	parent_node->op = op_node;
	op_node->next = NULL;
	op_node_prev = find_prev(head, op_node);
	op_node_prev->next = NULL;
	parent_node->left = make_tree(l_cmds);
	parent_node->right = make_tree(r_cmds);
	return (0);
}

void	del_tree(t_tree_node *node)
{
	if (node->left == NULL)
	{
		free_list(node->words);
		return ;
	}
	del_tree(node->left);
	free(node->left);
	node->left = NULL;
	del_tree(node->right);
	free(node->right);
	node->right = NULL;
	free_list(node->op);
}
