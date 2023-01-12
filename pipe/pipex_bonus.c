/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:09:00 by juha              #+#    #+#             */
/*   Updated: 2023/01/12 20:29:44 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_error(int error, char *str)
{
	if (error == -1)
	{
		perror(str);
		exit(1);
	}
}

static void	pipe_n_fork(t_pipe *p, t_using_pipe *channel)
{
	if (p->pid_num > 0 && p->operator_cmd != p->argc - 1)
		check_error(pipe(channel->fd), "pipex.c - 34");
	p->pid_num = fork();
	if (p->pid_num > 0)
	{
		_set_signal(0);
		if (channel->prev_fd != -1)
			close(channel->prev_fd);
		channel->prev_fd = channel->fd[READ];
		close(channel->fd[WRITE]);
	}
}

void	end_parent(t_pipe *p, t_using_pipe channel)
{
	int	i;
	int	status;

	i = p->operator_cmd;
	if (p->pid_num > 0)
	{
		close(channel.prev_fd);
		while (i--)
		{
			if (p->pid_num == waitpid(-1, &status, 0))
				p->status = status;
		}
	}
}

void	do_child(t_pipe *p, t_using_pipe *channel, \
				t_cplist *cmd, t_env_info_list *envp_list)
{
	if (p->pid_num == 0)
	{
		_set_signal(3);
		if (p->operator_cmd == 0)
			start_child(p, channel, cmd, envp_list);
		else if (p->operator_cmd == p->argc - 1)
			bottom_child(p, channel, cmd, envp_list);
		else
			other_child(p, channel, cmd, envp_list);
	}
}

int	pipex(t_cplist *cmd_pipe_list, t_fds *fds, \
			t_env_info_list *envp_list)
{
	t_pipe				p;
	t_using_pipe		channel;

	p.fds = fds;
	init(&p, &channel, cmd_pipe_list, envp_list);
	set_collabo(&p, p.envp);
	while (p.operator_cmd < p.argc)
	{
		pipe_n_fork(&p, &channel);
		if (p.pid_num == 0)
			break ;
		p.operator_cmd++;
	}
	do_child(&p, &channel, cmd_pipe_list, envp_list);
	end_parent(&p, channel);
/*
	g_error_code = WEXITSTATUS(p.status);
*/
	if (WIFEXITED(p.status))
		g_error_code = WEXITSTATUS(p.status);
	else if (WIFSIGNALED(p.status))
	{
		g_error_code = WTERMSIG(p.status);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (p.operator_cmd == 0)
		exit(1);
	return (0);
}
