/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:20:19 by gyim              #+#    #+#             */
/*   Updated: 2022/11/25 19:26:56 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
