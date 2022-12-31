/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:16 by gyim              #+#    #+#             */
/*   Updated: 2022/12/31 21:45:10 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

int	excute_leaf(t_tnode *cmd_list, t_fds *fd_info, t_env_info_list *envp_list)
{
	char	**cmd;

	expansion(cmd_list, envp_list);
	cmd = get_cmd(cmd_list);
	excute_cmd(cmd, fd_info, envp_list);
	free_cmd(cmd);
	return (0);
}

void	print_error(char *cmd, char *msg)
{
	write(2, BASH, ft_strlen(BASH));
	write(2, cmd, ft_strlen(cmd));
	write(2, msg, ft_strlen(msg));
}

int	excute_cmd(char **cmd, t_fds *fd_info, t_env_info_list *envp_list)
{
	char	**path;
	pid_t	pid;
	int		status;

	if (cmd_builtin_check1(cmd, envp_list) == 1)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_info->in_fd, STDIN_FILENO);
		dup2(fd_info->out_fd, STDOUT_FILENO);
		close(fd_info->in_fd);
		if (cmd_builtin_check2(cmd, envp_list) == 1)
			exit(0);
		path = get_path(envp_list);
		cmd_path_check(path, cmd, envp_list);
		print_error(cmd[0], CMD_NOT_FOUND);
		exit(127);
	}
	waitpid(0, &status, 0);
	g_error_code = WEXITSTATUS(status);
	return (0);
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
		builtin_exit(cmd);
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

void	cmd_path_check(char **path, char **cmd,
				t_env_info_list *envp_list)
{
	int		i;
	char	*cmd_path;
	char	**envp;

	i = 0;
	envp = envp_list_to_arr(envp_list);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd[0]);
		execve(cmd_path, cmd, envp);
		i++;
	}
	execve(cmd[0], cmd, envp);
}
