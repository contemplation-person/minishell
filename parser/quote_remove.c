/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:04:28 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 14:19:43 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	quote_remove(t_tnode *cmd_list)
{
	t_tnode	*curr;
	char	*removed;

	curr = cmd_list;
	while (curr)
	{
		removed = remove_token_quote(curr->token);
		free(curr->token);
		curr->token = removed;
		curr = curr->next;
	}
}

char	*remove_token_quote(char *token)
{
	char	**splitted;
	char	*ret;

	change_quote_char(token);
	splitted = ft_split(token, '\"');
	ret = concat_str(splitted);
	free_splitted(splitted);
	return (ret);
}

void	change_quote_char(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '\'')
			token[i] = '\"';
		i++;
	}
}

char	*concat_str(char **splitted)
{
	int		i;
	char	*ret;
	char	*delete;

	ret = ft_calloc(1, sizeof(char));
	i = 0;
	while (splitted[i])
	{
		delete = ret;
		ret = ft_strjoin(ret, splitted[i]);
		free(delete);
		delete = NULL;
		i++;
	}
	return (ret);
}

void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
