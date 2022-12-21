/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:16 by gyim              #+#    #+#             */
/*   Updated: 2022/12/21 13:23:01 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

int	excute_leaf(t_tnode *cmd_list, t_env_info_list *env_list)
{
	char	**cmd;

	cmd = get_cmd(cmd_list);
	excute_cmd(cmd, env_list);
	free_cmd(cmd);
	return (0);
}

int	excute_cmd(char **cmd, t_env_info_list *env_list)
{
	char	**path;
	int		i;
	char	*cmd_path;
	pid_t	pid;
	int		code;

	path = get_path(env_list);
	i = 0;

	pid = fork();
	if (pid == 0)
	{
		while (path[i])
		{
			cmd_path = ft_strjoin(path[i], "/");
			cmd_path = ft_strjoin(cmd_path, cmd[0]);
			execve(cmd_path, cmd, NULL);		
			i++;
		}
		execve(cmd_path, cmd, NULL);
		perror(NULL);
		exit(0);
	}
	wait(&code);
	printf("code : %d\n", code);
	free_path(path);
	return (0);
}

