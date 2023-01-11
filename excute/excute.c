/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:16 by gyim              #+#    #+#             */
/*   Updated: 2023/01/11 15:26:58 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	print_error(char *cmd, char *msg)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, msg, ft_strlen(msg));
}

int	excute_cmd(t_cplist *cmd_node, t_env_info_list *envp_list)
{
	char	**path;
	pid_t	pid;
	int		status;
	char	**cmd;

	cmd = ft_split(cmd_node->cmd, ' ');
	if (cmd_builtin_check1(cmd, envp_list) == 1)
		return (-999);
	pid = fork();
	if (pid == 0)
	{
		if (cmd_builtin_check2(cmd, envp_list) == 1)
			exit(0);
		path = get_path(envp_list);
		cmd_path_check(path, cmd, envp_list);
		print_error(cmd[0], CMD_NOT_FOUND);
		exit(127);
	}
	free_cmd(cmd);
	waitpid(-1, &status, 0);
	g_error_code = WEXITSTATUS(status);
	return (pid);
}

int	cmd_builtin_check1(char **cmd, t_env_info_list *envp_list)
{
	if (ft_strncmp(cmd[0], "cd", 3) == 0)
	{
		builtin_cd(envp_list, cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
	{
		builtin_export(envp_list, cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
	{
		builtin_unset(envp_list, cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "exit", 5) == 0)
	{
		g_error_code = builtin_exit(cmd);
		return (1);
	}
	else
		return (0);
}

int	cmd_builtin_check2(char **cmd, t_env_info_list *envp_list)
{
	if (ft_strncmp(cmd[0], "echo", 5) == 0)
	{
		echo(cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
	{
		builtin_pwd(cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
	{
		builtin_env(envp_list, cmd);
		return (1);
	}
	else
		return (0);
}
