/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:04:39 by gyim              #+#    #+#             */
/*   Updated: 2022/11/26 17:24:44 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_token_len(char **token)
{
	int	i;

	i = 0;
	while (token[i])
		i++;
	return (i);
}

int	p_start_check(char *token)
{
	if (token[0] == '(')
		return (BRACKET);
	else if (token[0] == '[')
		return (SQUARE_BRACKET);
	else if (token[0] == '\"')
		return (DOUBLE_SQUOTE);
	else if (token[0] == '\'')
		return (SINGLE_SQUOTE);
	else if (token[0] == '`')
		return (BACKTICK);
	return (0);
}

int	p_end_check(char *token)
{
	if (token[0] == ')')
		return (BRACKET);
	else if (token[0] == ']')
		return (SQUARE_BRACKET);
	else if (token[0] == '\"')
		return (DOUBLE_SQUOTE);
	else if (token[0] == '\'')
		return (SINGLE_SQUOTE);
	else if (token[0] == '`')
		return (BACKTICK);
	return (0);
}

char	**get_left_tokens(char *tokens[], int index)
{
	char	**ret;
	int		i;

	ret = malloc(sizeof(t_node *) * (index + 1));
	if (!ret)
		return (0);
	i = 0;
	ret[index] = 0;
	while (i < index)
	{
		ret[i] = tokens[i];
		i++;
	}
	return (ret);
}

char	**get_right_tokens(char *tokens[], int index, int size)
{
	char	**ret;
	int		i;
	int		j;

	ret = malloc(sizeof(t_node *) * (size - index));
	j = index + 1;
	i = 0;
	while (tokens[j])
	{
		ret[i] = tokens[j];
		j++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
