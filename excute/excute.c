/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:16 by gyim              #+#    #+#             */
/*   Updated: 2023/01/17 14:35:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

int	excute_cmd(t_cplist *cmd_node, t_env_info_list *envp_list)
{
	pid_t	pid;
	int		status;
	char	**cmd;

	cmd = split_cmd(cmd_node->cmd);
	if (cmd[0] == NULL)
	{
		g_error_code = 0;
		return (0);
	}
	if (cmd_builtin_check1(cmd, envp_list) == 1)
	{
		free_cmd(cmd);
		return (0);
	}
	_set_signal(0);
	pid = fork();
	excute_child(pid, cmd, envp_list);
	waitpid(-1, &status, 0);
	free_cmd(cmd);
	g_error_code = get_error_code(&status);
	return (g_error_code);
}

void	excute_child(int pid, char **cmd, t_env_info_list *envp_list)
{
	char	**path;

	if (pid == 0)
	{
		_set_signal(2);
		if (cmd_builtin_check2(cmd, envp_list) == 1)
		{
			free_cmd(cmd);
			exit(0);
		}
		path = get_path(envp_list);
		cmd_path_check(path, cmd, envp_list);
		print_error(cmd[0], CMD_NOT_FOUND);
		exit(127);
	}
}

int	get_error_code(int *status)
{
	if (WIFEXITED(*status))
		g_error_code = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
	{
		g_error_code = 128 + WTERMSIG(*status);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (g_error_code);
}

void	excute_all(t_cplist *cmd_pipe_list, t_fds *fds,
				t_env_info_list *envp_list)
{
	int		argc;

	argc = cplist_len(cmd_pipe_list);
	reset_fds(fds);
	create_heredoc(cmd_pipe_list) == FALSE);
	_set_signal(2);
	if (argc <= 1)
		pipex2(cmd_pipe_list, fds, envp_list);
	else
		pipex(cmd_pipe_list, fds, envp_list);
	close(fds->in_fd);
	close(fds->out_fd);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(fds->stdin_fd, STDIN_FILENO);
	dup2(fds->stdout_fd, STDOUT_FILENO);
}
