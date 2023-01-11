/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:09:00 by juha              #+#    #+#             */
/*   Updated: 2023/01/11 21:17:07 by juha             ###   ########seoul.kr  */
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
	_set_signal(2); // 시그널 처리 필요.
	if (p->pid_num > 0)
	{
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

void	do_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd)
{
	if (p->pid_num == 0)
	{
		if (p->operator_cmd == 0)
			start_child(p, channel, cmd);
		else if (p->operator_cmd == p->argc - 1)
			bottom_child(p, channel, cmd);
		else
			other_child(p, channel, cmd);
	}
}

int	pipex(t_cplist *cmd_pipe_list,
			t_env_info_list *envp_list)
{
	t_pipe				p;
	t_using_pipe		channel;

	init(&p, &channel, cmd_pipe_list, envp_list);
	set_collabo(&p, p.envp);
	while (p.operator_cmd < p.argc)
	{
		pipe_n_fork(&p, &channel);
		if (p.pid_num == 0)
			break ;
		p.operator_cmd++;
	}
	do_child(&p, &channel, cmd_pipe_list);
	end_parent(&p, channel);
	return (WEXITSTATUS(p.status));
}
