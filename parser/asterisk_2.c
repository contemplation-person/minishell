/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:10:50 by gyim              #+#    #+#             */
/*   Updated: 2023/01/06 13:21:48 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	analyze_patten(char *sub_token, char *d_name, int *sub_idx, int *d_idx)
{
	if (sub_token[(*sub_idx)] == d_name[(*d_idx)])
	{
		++(*sub_idx);
		++(*d_idx);
	}
	else if (d_name[*d_idx] != '.' && sub_token[(*sub_idx)] == '*')
	{
		if (sub_token[(*sub_idx)])
			++(*sub_idx);
	}
	else if (sub_token[(*sub_idx)] != d_name[(*d_idx)])
	{
		if (!(*sub_idx))
			return (0);
		else if (sub_token[(*sub_idx) - 1] == '*')
			(*d_idx)++;
		else
			while ((*sub_idx) && sub_token[(*sub_idx) - 1] != '*')
				--(*sub_idx);
	}
	else
		++(*d_idx);
	return (1);
}

int	is_same_patten(char *sub_token, char *d_name)
{
	int	sub_idx;
	int	d_idx;

	sub_idx = 0;
	d_idx = 0;
	while (d_name[d_idx])
	{
		if (!analyze_patten(sub_token, d_name, &sub_idx, &d_idx))
			return (0);
	}
	while (sub_token[sub_idx] == '*')
		sub_idx++;
	return (d_name[d_idx] == sub_token[sub_idx]);
}
