/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:42:06 by gyim              #+#    #+#             */
/*   Updated: 2022/11/24 16:06:19 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**parser(char *input)
{
	char	**tokens;
	char	*tmp;
	int		i;
	char	*env_var;

	tmp = ft_strdup(input);
	change_wspace(tmp);
	tokens = ft_split(tmp, ' ');
	free(tmp);
	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '$')
		{
			env_var = getenv(tokens[i]);
			free(tokens[i]);
			tokens[i] = env_var;
		}
		printf("%s\n", tokens[i++]);
	}
	return (tokens);
}

void	change_wspace(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\t' || tmp[i] == '\n')
			tmp[i] = ' ';
		i++;
	}
}


void	free_line(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}
