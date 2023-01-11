/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:31:01 by juha              #+#    #+#             */
/*   Updated: 2023/01/11 16:09:22 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*access_file(t_pipe *p, t_using_pipe *channel, int ok)
{
	char	*ret;
	char	**path;
	char	**file;

	channel = NULL;
	file = ft_split(p->argv[p->operator_cmd], ' ');
	file[0] = ft_strjoin("/", file[0]);
	path = p->path;
	while (*path)
	{
		ret = ft_strjoin(*path, file[0]);
		if (!access(ret, ok))
			return (ret);
		path++;
	}
	if (!access(&file[0][1], ok))
		return (ft_strdup(&file[0][1]));
	p->status = 127;
	return (NULL);
}

char	**parse_option(t_pipe p, t_using_pipe channel)
{
	char	**ret;

	ret = ft_split(p.argv[p.operator_cmd], ' ');
	ret[0] = access_file(&p, &channel, F_OK);
	return (ret);
}

void	start_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd)
{
	char	*file;
	int		check_dup;

	check_dup == -1;
	close(channel->fd[READ]);
	check_dup = dup2(channel->fd[WRITE], STDOUT_FILENO);
	close(channel->fd[WRITE]);
	if (check_dup == -1)
		exit(check_dup);
	excute_redirection(p, cmd);
	/*
		builtin check
	*/
	exit(execve(file, parse_option(*p, *channel), p->envp));
}

void	other_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd)
{
	char	*file;
	int		check_dup;

	//printf("other\tso what???\n");//
	check_dup == -1;
	close(channel->fd[READ]);
	check_dup = dup2(channel->prev_fd, STDIN_FILENO);
	if (check_dup == -1)
		exit(check_dup);
	close(channel->prev_fd);
	check_dup = dup2(channel->fd[WRITE], STDOUT_FILENO);
	if (check_dup == -1)
		exit(check_dup);
	close(channel->fd[WRITE]);
	/*
		builtin check
	*/
	excute_redirection(p, cmd);
	exit(execve(file, parse_option(*p, *channel), p->envp));
}

void	bottom_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd)
{
	char	*file;
	int		check_dup;

	check_dup == -1;
	//printf("bottom\tcheck bottom -  stdread : %d\n", channel->prev_fd);//
	check_dup = dup2(channel->prev_fd, STDIN_FILENO);
	if (check_dup == -1)
		exit(check_dup);
	close(channel->prev_fd);
	excute_redirection(p, cmd);
	exit(execve(file, parse_option(*p, *channel), p->envp));
}
