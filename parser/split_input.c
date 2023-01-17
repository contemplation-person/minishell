/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:51:34 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 14:36:47 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tlist_info	*split_input(char *input)
{
	t_tlist_info	*tinfo;
	int				i;

	tinfo = tlist_init();
	i = 0;
	while (input + i)
	{
		while (input[i] && is_space(input[i]))
			i++;
		if (!input[i])
			break ;
		i += get_token(tinfo, input, i);
	}
	return (tinfo);
}

int	get_token(t_tlist_info *list, char *input, int start)
{
	int	end;

	if (is_op(input, start))
	{
		end = get_op_end(input, start);
		add_substr(list, input, start, end - 1);
		return (end - start);
	}
	else if (is_paren(input, start))
	{
		add_substr(list, input, start, start);
		return (1);
	}
	else
	{
		end = get_word_end(input, start);
		add_substr(list, input, start, end - 1);
		return (end - start);
	}
}
