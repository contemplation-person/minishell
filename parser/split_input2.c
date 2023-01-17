/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:59:29 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 18:41:52 by gyim             ###   ########seoul.kr  */
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
	else if (!ft_strncmp(input + start, "|", 1))
		end = start + 1;
	else if (!ft_strncmp(input + start, ">", 1))
		end = start + 1;
	else if (!ft_strncmp(input + start, "<", 1))
		end = start + 1;
	return (end);
}

int	get_word_end(char *input, int start)
{
	int		end;
	char	quote;

	end = start;
	while (input[end] && !is_op(input, end)
		&& !is_paren(input, end) && !is_space(input[end]))
	{
		if (input[end] == '\'' || input[end] == '\"')
		{
			quote = input[end];
			end++;
			while (input[end] && input[end] != quote)
				end++;
		}
		end++;
	}
	return (end);
}

void	add_substr(t_tlist_info *list, char *str, int start, int end)
{
	char	*word;

	word = ft_substr(str, start, end - start + 1);
	if (!word)
		return ;
	list_add(list, word);
	free(word);
}
