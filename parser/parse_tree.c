/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:48:31 by gyim              #+#    #+#             */
/*   Updated: 2022/11/26 10:00:09 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*parse_tree(char **tokens)
{
	t_node	*new_node;
	int		op_index;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	op_index = op_check(tokens);
	if (op_index == -1)
	{
		new_node->op = 0;
		new_node->tokens = tokens;
		new_node->left = 0;
		new_node->right = 0;
	}
	else
	{
		new_node->op = tokens[op_index];
		if (!make_child(new_node, tokens, op_index))
		{
			free(new_node);
			return (0);
		}
	}
	return (new_node);
}

int	make_child(t_node *parent, char **tokens, int index)
{
	int		size;
	char	**left_tokens;
	char	**right_tokens;

	size = get_tokens_size(tokens);
	parent->tokens = 0;
	left_tokens = get_left_tokens(tokens, index);
	if (!left_tokens)
		return (0);
	right_tokens = get_right_tokens(tokens, index, size);
	if (!right_tokens)
	{
		free(left_tokens);
		return (0);
	}
	if (!parse_tree(left_tokens))
		return (0);
	if (!parse_tree(right_tokens))
		return (0);
	return (1);
}

int	get_tokens_size(char **token)
{
	int	i;

	i = 0;
	while (token[i])
		i++;
	return (i);
}

int	op_check(char **tokens)
{
	int	i;
	int	ret;

	ret = -1;
	i = 0;
	while (tokens[i])
	{
		if (is_op(tokens[i]) == 1)
			ret = i;
		i++;
	}
	return (ret);
}

int	is_op(char *token)
{
	if (ft_strncmp(token, "||", 3) == 0)
		return (1);
	else if (ft_strncmp(token, "&&", 3) == 0)
		return (1);
	else
		return (0);
}
