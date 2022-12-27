/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:22:27 by gyim              #+#    #+#             */
/*   Updated: 2022/12/27 15:07:56 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	else
		return (0);
}

int	is_quote(char *input, int index)
{
	if (input[index] == '\'')
		return (SINGLE_QUOTE);
	else if (input[index] == '"')
		return (DOUBLE_QUOTE);
	else if (input[index] == '`')
		return (BACKTICK);
	else
		return (0);
}

int	is_paren(char *input, int index)
{
	if (input[index] == '(' || input[index] == ')')
		return (1);
	else if (input[index] == '[' || input[index] == ']')
		return (1);
	else
		return (0);
}

int	is_op(char *input, int index)
{
	if (input[index] == '|')
		return (1);
	else if (input[index] == '>')
		return (1);
	else if (input[index] == '<')
		return (1);
	else if (!ft_strncmp(input + index, "||", 2))
		return (1);
	else if (!ft_strncmp(input + index, "&&", 2))
		return (1);
	else if (!ft_strncmp(input + index, ">>", 2))
		return (1);
	else if (!ft_strncmp(input + index, "<<", 2))
		return (1);
	else
		return (0);
}
