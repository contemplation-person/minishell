/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:04:30 by gyim              #+#    #+#             */
/*   Updated: 2022/12/27 19:42:11 by gyim             ###   ########seoul.kr  */
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
	if (head == op_node || !op_node->next
		|| make_child(new_node, head, op_node) == -1)
	{
		free(new_node);
		return (NULL);
	}
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
	if (l_cmds != op_node)
		parent_node->left = make_tree(l_cmds);
	else
		parent_node->left = NULL;
	if (r_cmds != NULL)
		parent_node->right = make_tree(r_cmds);
	else
		parent_node->right = NULL;
	return (0);
}

void	del_sublist(t_tnode	*head)
{
	t_tnode	*curr;
	t_tnode	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr->token);
		free(curr);
		curr = next;
	}
}

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
