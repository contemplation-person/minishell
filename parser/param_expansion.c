/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:08 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 19:52:30 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*find_variable(char *token, int start, int end,
					t_env_info_list *env_list)
{
	t_env_info	*curr;
	char		*temp;
	char		*ret;
	char		*code;

	if (ft_strncmp("$?", token + start, ft_strlen("$?")) == 0)
	{
		temp = ft_substr(token, start + 2, end - start - 1);
		code = ft_itoa(g_error_code);
		ret = ft_strjoin(code, temp);
		free(code);
		free(temp);
		return (ret);
	}
	end = 0;
	curr = env_list->env_info;
	while (curr)
	{
		if (ft_strncmp(curr->key, token + start + 1, ft_strlen(curr->key))
			== 0)
			return (ft_strdup(curr->value));
		curr = curr->next;
	}
	return (ft_strdup(""));
}

char	*dollar_expand(char *token, int start, int end,
					t_env_info_list *env_list)
{
	char	*ret;

	if (token[start] != '$')
		ret = ft_substr(token, start, end - start + 1);
	else
		ret = find_variable(token, start, end, env_list);
	return (ret);
}

char	*p_expansion(char *token, t_env_info_list *env_list)
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
		if (token[i] == '\'')
		{
			i++;
			while (token[i] && token[i] != '\'')
				i++;
			i++;
		}
		if (token[i + 1] == '$' || token[i + 1] == '\0'
			|| token[i + 1] == '\"' || token[i + 1] == '\'')
		{
			prev = ret;
			temp = dollar_expand(token, start, i, env_list);
			ret = ft_strjoin(prev, temp);
			free(temp);
			free(prev);
			start = i + 1;
		}
		i++;
	}
	return (ret);
}

int	expansion(t_tnode *head, t_env_info_list *env_list)
{
	t_tnode	*curr;
	char	*p_expanded;
	char	*a_expanded;

	curr = head;
	while (curr)
	{
		p_expanded = p_expansion(curr->token, env_list);
		a_expanded = asterisk(p_expanded);
		free(curr->token);
		free(p_expanded);
		curr->token = NULL;
		curr->token = a_expanded;
		curr = curr->next;
	}
	return (0);
}
