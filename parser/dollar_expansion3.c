/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:00:00 by gyim              #+#    #+#             */
/*   Updated: 2023/01/18 10:07:33 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_quote(char *token, int *i, int *double_quote)
{
	if (token[*i] == '\"')
		*double_quote = 1 - *double_quote;
	if (token[*i] == '\'' && *double_quote == 0)
		skip_s_quote(token, i);
}

void	*ft_strjoin_free(char **ret, char *temp, char *prev)
{
	*ret = ft_strjoin(prev, temp);
	free(temp);
	free(prev);
	return (ret);
}
