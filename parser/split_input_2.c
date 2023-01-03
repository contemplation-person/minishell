/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:59:29 by gyim              #+#    #+#             */
/*   Updated: 2023/01/03 14:05:19 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_op_end(char *input, int start)
{
	int	end;

	end = start;
	if (!ft_strncmp(input + start, "||", 2))
		end = start + 2;
	else if (!ft_strncmp(input + start, "&&", 2))
		end = start + 2;
	else if (!ft_strncmp(input + start, ">>", 2))
		end = start + 2;
	else if (!ft_strncmp(input + start, "<<", 2))
		end = start + 2;
	else if (input[start] == '|')
		end = start + 1;
	else if (input[start] == '>')
		end = start + 1;
	else if (input[start] == '<')
		end = start + 1;
	return (end);
}

int	get_quoted_end(char *input, int start)
{
	char	quote;
	int		end;

	quote = *(input + start);
	end = start + 1;
	while (input[end] && input[end] != quote)
		end++;
	return (end);
}

int	get_word_end(char *input, int start)
{
	int	end;

	end = start;
	while (input[end] && !is_op(input, end)
		&& !is_paren(input, end) && !is_space(input[end])
		&& !is_quote(input, end))
		end++;
	return (end);
}
