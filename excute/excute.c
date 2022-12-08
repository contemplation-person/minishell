/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:15:08 by gyim              #+#    #+#             */
/*   Updated: 2022/12/08 17:39:09 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

// void	excute(char **cmds)
// {

// }

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		// printf("%s\n", envp[i]);
		if (!ft_strncmp(envp[i], "PATH=", 5))
			path = ft_strdup(envp[i]);
		i++;
	}
	paths = ft_split(path + 5, ':');
	free(path);
	path = NULL;
	
	return (0);
}
