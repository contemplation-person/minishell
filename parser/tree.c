/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:48:31 by gyim              #+#    #+#             */
/*   Updated: 2022/11/28 10:11:37 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*make_tree(char **token)
{
	int		token_len;
	int		op_index;
	t_node	*node;
	char	**left_token;
	char	**right_token;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	token_len = get_token_len(token);
	op_index = get_op_index(token);
	node->token = get_sub_token(token, 0, token_len);
	if (op_index == -1)
	{
		node->left = NULL;
		node->right = NULL;
		return (node);
	}
	make_sub_tree(node, token_len);
	return (node);
}

int	make_sub_tree(t_node *node, int token_len)
{
	int		op_index;
	char	**left_token;
	char	**right_token;

	op_index = get_op_index(node->token);
	if (op_index == token_len)
	{
		node->left = NULL;
		node->right = NULL;
		return (0);
	}
	node->op = 1;
	left_token = get_sub_token(node->token, 0, op_index - 1);
	right_token = get_sub_token(node->token, op_index + 1, token_len);
	node->left = make_tree(left_token);
	node->right = make_tree(right_token);
	return (0);
}

char	**get_sub_token(char **token, int start, int end)
{
	char	**ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char *) * (end - start + 2));
	i = 0;
	j = start;
	while (j <= end)
	{
		ret[i] = token[j];
		i++;
		j++;
	}
	ret[i] = NULL;
	return (ret);
}
