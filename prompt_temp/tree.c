/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:34:41 by gyim              #+#    #+#             */
/*   Updated: 2022/12/07 10:18:41 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "split_input.h"

t_node	*make_tree(char **cmds)
{
	int		op_index;
	t_node	*new_node;

	print_cmds(cmds);
	op_index = find_op(cmds);
	new_node = make_new_node();
	if (new_node == NULL)
		return (NULL);
	if (op_index == -1)
	{
		new_node->words = cmds;
		return (new_node);
	}
	if (make_child(new_node, cmds, op_index) == -1)
		return (NULL);
	else
		return (new_node);
}

t_node	*make_new_node(void)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->op = NULL;
	new_node->words = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

int	make_child(t_node *parent_node, char **cmds, int op_index)
{
	char	**l_cmds;
	char	**r_cmds;
	int		len;

	len = cmds_len(cmds);
	parent_node->op = ft_strdup(cmds[op_index]);
	l_cmds = subcmds(cmds, 0, op_index - 1);
	if (l_cmds == NULL)
		return (-1);
	r_cmds = subcmds(cmds, op_index + 1, len - 1);
	if (r_cmds == NULL)
	{
		free_cmds(l_cmds);
		return (-1);
	}
	parent_node->left = make_tree(l_cmds);
	printf("%s\n", parent_node->op);
	parent_node->right = make_tree(r_cmds);
	// free_cmds(cmds);
	return (0);
}
