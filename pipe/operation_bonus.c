/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:31:01 by juha              #+#    #+#             */
/*   Updated: 2023/01/12 16:05:52 by juha             ###   ########seoul.kr  */
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

void	start_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd, t_env_info_list *envp_list)
{
	int		check_dup;
	char	**option_file;

	check_dup = -1;
	close(channel->fd[READ]);
	check_dup = dup2(channel->fd[WRITE], STDOUT_FILENO);
	close(channel->fd[WRITE]);
	if (check_dup == -1)
		exit(check_dup);
	(void) cmd;
	(void) envp_list;
	excute_redirection(p, cmd);
	if (cmd_builtin_check1(&(cmd->cmd), envp_list) \
		|| cmd_builtin_check2(&(cmd->cmd), envp_list))
		exit(0);

	//int i = 0;
	//char **test = parse_option(*p);
	//write(2, p->argv[p->operator_cmd], ft_strlen(p->argv[p->operator_cmd]));
	//write(2, " : \n", 4);
	//while (test[i])
	//{
	//	write(2, test[i], ft_strlen(test[i]));
	//	//test = parse_option(*p, *channel)[1];	
	//	//write(2, test, ft_strlen(test));
	//	write(2, "\n", 1);
	//	i++;
	//}

	option_file = parse_option(*p);
	exit(execve(option_file[0], parse_option(*p), p->envp));
}

void	other_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd, t_env_info_list *envp_list)
{
	int		check_dup;
	char	**option_file;
	
	//printf("other\tso what???\n");//
	check_dup = -1;
	close(channel->fd[READ]);
	check_dup = dup2(channel->prev_fd, STDIN_FILENO);
	if (check_dup == -1)
		exit(check_dup);
	close(channel->prev_fd);
	check_dup = dup2(channel->fd[WRITE], STDOUT_FILENO);
	if (check_dup == -1)
		exit(check_dup);
	close(channel->fd[WRITE]);
	(void) cmd;
	(void) envp_list;
	excute_redirection(p, cmd);
	if (cmd_builtin_check1(&(cmd->cmd), envp_list) \
		|| cmd_builtin_check2(&(cmd->cmd), envp_list))
		exit(0);
	option_file = parse_option(*p);
	exit(execve(option_file[0], parse_option(*p), p->envp));
}

void	bottom_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd, t_env_info_list *envp_list)
{
	int		check_dup;
	char	**option_file;

	check_dup = -1;
	//printf("bottom\tcheck bottom -  stdread : %d\n", channel->prev_fd);//
	check_dup = dup2(channel->prev_fd, STDIN_FILENO);
	if (check_dup == -1)
		exit(check_dup);
	close(channel->prev_fd);
	(void) cmd;
	(void) envp_list;
	excute_redirection(p, cmd);
	if (cmd_builtin_check1(&(cmd->cmd), envp_list) \
		|| cmd_builtin_check2(&(cmd->cmd), envp_list))
		exit(0);

	//int i = 0;
	//char **test = parse_option(*p);
	//while (test[i])
	//{
	//	write(2, p->argv[p->operator_cmd], ft_strlen(p->argv[p->operator_cmd]));
	//	write(2, test[i], ft_strlen(test[i]));
	//	//test = parse_option(*p, *channel)[1];	
	//	//write(2, test, ft_strlen(test));
	//	write(2, "\n", 1);
	//	i++;
	//}
	
	option_file = parse_option(*p);
	exit(execve(option_file[0], parse_option(*p), p->envp));
}
