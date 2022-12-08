/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:22:27 by gyim              #+#    #+#             */
/*   Updated: 2022/12/03 18:53:35 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "split_input.h"

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

int	is_brace(char *input, int index)
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
