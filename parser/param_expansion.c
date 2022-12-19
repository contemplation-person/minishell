/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:08 by gyim              #+#    #+#             */
/*   Updated: 2022/12/19 19:56:45 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*find_variable(char *token, int srart, int end)
{
	const char	*test = "dollar_changed";

	return (ft_strdup(test));
}

char	*dollar_expand(char *token, int start, int end)
{
	char	*ret;

	if (token[start] != '$')
		ret = ft_substr(token, start, end - start + 1);
	else
		ret = find_variable(token, start, end - start + 1);
}

char	*p_expansion(char *token)

{
	int		start;
	int		i;
	char	*temp;
	char	*ret;

	i = 0;
	start = 0;
	while (token[i])
	{
		if (token[i + 1] == '$' || token[i + 1] == '\0')
		{
			temp = dollar_expand(token, start, i - start + 1);
			start = i + 1;
		}
		i++;
	}
}

