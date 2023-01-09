/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:09:25 by gyim              #+#    #+#             */
/*   Updated: 2023/01/09 13:41:01 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

int	pipe_excute_leaf(t_tnode *cmd_list, t_fds *fd_info,
	t_env_info_list *envp_list)
{
	char	**cmd;
	t_rnode	*rd_head;
	int		pid;

	expansion(cmd_list, envp_list);
	retokenize(cmd_list);
	quote_remove(cmd_list);
	rd_head = get_redirection(cmd_list);
	cmd = get_cmd(cmd_list);
	if (set_fds(fd_info, rd_head, envp_list) == -1)
	{
		free_red(rd_head);
		free_cmd(cmd);
		return (-1);
	}
	if (cmd[0])
		pid = pipe_excute_cmd(cmd, fd_info, envp_list);
	else
		pid = -999;
	free_red(rd_head);
	free_cmd(cmd);
	return (pid);
}

int	pipe_excute_cmd(char **cmd, t_fds *fd_info, t_env_info_list *envp_list)
{
	char	**path;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd_info->in_fd, STDIN_FILENO);
		dup2(fd_info->out_fd, STDOUT_FILENO);
		close(fd_info->in_fd);
		close(fd_info->out_fd);
		if (cmd_builtin_check1(cmd, envp_list) == 1)
			exit(0);
		if (cmd_builtin_check2(cmd, envp_list) == 1)
			exit(0);
		path = get_path(envp_list);
		cmd_path_check(path, cmd, envp_list);
		print_error(cmd[0], CMD_NOT_FOUND);
		exit(127);
	}
	return (pid);
}
