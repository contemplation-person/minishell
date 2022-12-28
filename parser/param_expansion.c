/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:08 by gyim              #+#    #+#             */
/*   Updated: 2022/12/28 16:22:05 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*find_variable(char *token, int start, int end)
{
	const char	*test = "$$$$$";
	const char	*target = "$asdf";

	if (ft_strncmp(token + start, target, 5) == 0
		&& (token[start + 5] == '\0' || token[start + 5] == '$'))
		return (ft_strdup(test));
	else
		return (ft_substr(token, start, end - start + 1));
}

char	*dollar_expand(char *token, int start, int end)
{
	char	*ret;

	if (token[start] != '$')
		ret = ft_substr(token, start, end - start + 1);
	else
		ret = find_variable(token, start, end - start + 1);
	return (ret);
}

char	*p_expansion(char *token)
{
	int		start;
	int		i;
	char	*temp;
	char	*ret;
	char	*prev;

	i = 0;
	start = 0;
	ret = calloc(sizeof(char), 1);
	if (!ret)
		return (NULL);
	while (token[i])
	{
		if (token[i + 1] == '$' || token[i + 1] == '\0')
		{
			prev = ret;
			temp = dollar_expand(token, start, i - start + 1);
			ret = ft_strjoin(prev, temp);
			free(temp);
			free(prev);
			start = i + 1;
		}
		i++;
	}
	return (ret);
}

int	expansion(t_tnode *head)
{
	t_tnode	*curr;
	char	*expanded;

	curr = head;
	while (curr)
	{
		expanded = p_expansion(curr->token);
		// * expansion
		free(curr->token);
		curr->token = NULL;
		curr->token = expanded;
		curr = curr->next;
	}
	return (0);
}
