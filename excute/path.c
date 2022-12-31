/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:39:25 by gyim              #+#    #+#             */
/*   Updated: 2022/12/31 12:33:04 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

char	**get_path(t_env_info_list *env_list)
{
	t_env_info	*curr;
	char		*value;
	char		**path;

	curr = env_list->env_info;
	path = NULL;
	value = NULL;
	while (curr)
	{
		if (!ft_strncmp(curr->key, "PATH", 5))
		{
			value = curr->value;
			break ;
		}
		curr = curr->next;
	}
	if (value)
		path = ft_split(value, ':');
	return (path);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	free(path);
}
