/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:13:54 by gyim              #+#    #+#             */
/*   Updated: 2023/01/06 10:43:11 by gyim             ###   ########seoul.kr  */
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

void	skip_s_quote(char *token, int *index)
{
	(*index)++;
	while (token[*index] && token[(*index)] != '\'')
		(*index)++;
	(*index)++;
}

void	dollar_token_change(char **ret, char *token, t_env_info_list *env_list)
{
	int		i;
	char	*temp;
	char	*prev;
	int		start;

	start = 0;
	i = 0;
	while (token[i])
	{
		if (token[i] == '\'')
			skip_s_quote(token, &i);
		if (token[i + 1] == '$' || token[i + 1] == '\0'
			|| token[i + 1] == '\"' || token[i + 1] == '\''
			|| token[i + 1] == ' ')
		{
			prev = *ret;
			temp = dollar_expand(token, start, i, env_list);
			*ret = ft_strjoin(prev, temp);
			free(temp);
			free(prev);
			start = i + 1;
		}
		i++;
	}
}

char	*p_token_expansion(char *token, t_env_info_list *env_list)
{
	char	*ret;

	ret = ft_calloc(sizeof(char), 1);
	if (!ret)
		return (NULL);
	dollar_token_change(&ret, token, env_list);
	return (ret);
}
