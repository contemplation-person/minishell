/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:31:01 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 13:22:58 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*access_file(t_pipe *p, int ok)
{
	char	*ret;
	char	**path;
	char	**file;

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
	g_error_code = 127;
	return (NULL);
}

char	**parse_option(t_pipe p)
{
	char	**ret;

	ret = ft_split(p.argv[p.operator_cmd], ' ');
	ret[0] = access_file(&p, F_OK);
	return (ret);
}

void	start_child(t_pipe *p, t_using_pipe *channel, \
			t_cplist *cmd, t_env_info_list *envp_list)
{
	int		check_dup;
	char	**option_file;
	char	**builtin_cmd;

	check_dup = -1;
	close(channel->fd[READ]);
	check_dup = dup2(channel->fd[WRITE], STDOUT_FILENO);
	close(channel->fd[WRITE]);
	if (check_dup == -1)
		exit(check_dup);
	if (excute_redirection(p, cmd) == FALSE)
		exit(1);
	builtin_cmd = ft_split(p->argv[p->operator_cmd], ' ');
	if (cmd_builtin_check1(builtin_cmd, envp_list) \
		|| cmd_builtin_check2(builtin_cmd, envp_list))
		exit(0);
	option_file = parse_option(*p);
	execve(builtin_cmd[0], parse_option(*p), p->envp);
	execve(option_file[0], parse_option(*p), p->envp);
	print_error(builtin_cmd[0], CMD_NOT_FOUND);
	exit(127);
}

void	other_child(t_pipe *p, t_using_pipe *channel, \
					t_cplist *cmd, t_env_info_list *envp_list)
{
	int		check_dup;
	char	**option_file;
	char	**builtin_cmd;

	check_dup = -1;
	close(channel->fd[READ]);
	check_dup = dup2(channel->prev_fd, STDIN_FILENO);
	close(channel->prev_fd);
	if (check_dup == -1)
		exit(check_dup);
	check_dup = dup2(channel->fd[WRITE], STDOUT_FILENO);
	close(channel->fd[WRITE]);
	if (check_dup == -1)
		exit(check_dup);
	builtin_cmd = ft_split(p->argv[p->operator_cmd], ' ');
	if (excute_redirection(p, cmd) == FALSE)
		exit(1);
	if (cmd_builtin_check1(builtin_cmd, envp_list) \
		|| cmd_builtin_check2(builtin_cmd, envp_list))
		exit(0);
	option_file = parse_option(*p);
	execve(builtin_cmd[0], parse_option(*p), p->envp);
	execve(option_file[0], parse_option(*p), p->envp);
	print_error(builtin_cmd[0], CMD_NOT_FOUND);
	exit(127);
}

void	bottom_child(t_pipe *p, t_using_pipe *channel, \
					t_cplist *cmd, t_env_info_list *envp_list)
{
	int		check_dup;
	char	**option_file;
	char	**builtin_cmd;

	check_dup = -1;
	check_dup = dup2(channel->prev_fd, STDIN_FILENO);
	if (check_dup == -1)
		exit(check_dup);
	close(channel->prev_fd);
	if (excute_redirection(p, cmd) == FALSE)
		exit(1);
	builtin_cmd = ft_split(p->argv[p->operator_cmd], ' ');
	if (cmd_builtin_check1(builtin_cmd, envp_list) \
		|| cmd_builtin_check2(builtin_cmd, envp_list))
		exit(0);
	option_file = parse_option(*p);
	execve(builtin_cmd[0], parse_option(*p), p->envp);
	execve(option_file[0], parse_option(*p), p->envp);
	print_error(builtin_cmd[0], CMD_NOT_FOUND);
	exit(127);
}
