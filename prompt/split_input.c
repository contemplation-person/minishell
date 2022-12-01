/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:51:34 by gyim              #+#    #+#             */
/*   Updated: 2022/12/01 20:28:12 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "split_input.h"

// split_input 
// 1. split quote

t_tlist_info	*split_input(char *input)
{
	t_tlist_info	*tinfo;
	int				i;
	int				start;

	tinfo = tlist_init();
	start = 0;
	i = 0;
	while (input[i])
	{
		
	}
	return (tinfo);
}

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	else
		return (0);
}

int	is_quote(char ch)
{
	if (ch == '\'')
		return (SINGLE_QUOTE);
	else if (ch == '"')
		return (DOUBLE_QUOTE);
	else if (ch == '`')
		return (BACKTICK);
	else
		return (0);
}

int	is_brace(char input)
{
	if (input == '(' || input == ')')
	 	return (1);
	else if (input == '[' || input == ']')
		return (1);
	else
		return (0);
}

int	is_op(char *str)
{
	if (*str == '|')
		return (1);
	else
		return (0);
}

void	add_substr(t_tlist_info *list, char *str, int start, int end)
{
	char	*word;

	word = ft_substr(str, start, end);
	if (!word)
		return ;
	list_add(list, word);
	free(word);
}
