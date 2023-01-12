/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:16 by gyim              #+#    #+#             */
/*   Updated: 2023/01/12 23:08:28 by juha             ###   ########seoul.kr  */
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
	_set_signal(0);
	pid = fork();
	if (pid == 0)
	{
		_set_signal(3);
		if (cmd_builtin_check2(cmd, envp_list) == 1)
			exit(0);
		path = get_path(envp_list);
		cmd_path_check(path, cmd, envp_list);
		print_error(cmd[0], CMD_NOT_FOUND);
		exit(127);
	}
	waitpid(-1, &status, 0);
	free_cmd(cmd);
	if (WIFEXITED(status))
		g_error_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_error_code = WTERMSIG(status);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
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

void	excute_all(t_cplist *cmd_pipe_list, t_fds *fds,
				t_env_info_list *envp_list)
{
	int		argc;
	char	**envp;

	envp = get_envp(envp_list);
	argc = cplist_len(cmd_pipe_list);
	reset_fds(fds);
/*
	여기서 히어독을 받고 파일이름을 넘겨준다.
*/
	if (argc <= 1)
	{
		redirection(fds, cmd_pipe_list->rd_head, envp_list);
		init_fds(fds);
		excute_cmd(cmd_pipe_list, envp_list);
	}
	else
		pipex(cmd_pipe_list, fds, envp_list);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(fds->stdin_fd, STDIN_FILENO);
	dup2(fds->stdout_fd, STDOUT_FILENO);
}
