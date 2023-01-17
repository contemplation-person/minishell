/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:06:56 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 14:47:45 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*error_code_expansion(char *token, int start, int end)
{
	char	*target;
	char	*code;
	char	*ret;

	target = ft_substr(token, start + 2, end - start - 1);
	code = ft_itoa(g_error_code);
	ret = ft_strjoin(code, target);
	free(code);
	free(target);
	return (ret);
}

char	*env_key_to_value(char *token, int start, int end,
					t_env_info_list *env_list)
{
	t_env_info	*curr;
	char		*target;

	curr = env_list->env_info;
	target = ft_substr(token, start + 1, end - start);
	while (curr)
	{
		if (ft_strncmp(curr->key, target, ft_strlen(curr->key) + 1)
			== 0)
		{
			free(target);
			return (ft_strdup(curr->value));
		}
		curr = curr->next;
	}
	free(target);
	if (ft_strncmp(token + start, "$", 2) == 0)
		return (ft_strdup("$"));
	return (ft_strdup(""));
}
