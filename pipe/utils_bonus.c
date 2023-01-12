/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:10:47 by juha              #+#    #+#             */
/*   Updated: 2023/01/12 16:19:56 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_cpl_num(t_cplist *cmd_pipe_list)
{
	t_cplist	*temp;
	int			i;

	i = 0;
	temp = cmd_pipe_list;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	init(t_pipe *p, t_using_pipe *channel, \
			t_cplist *cmd_pipe_list, t_env_info_list *envp_list)
{
	ft_bzero(channel, sizeof(t_using_pipe));
	ft_bzero(p, sizeof(t_pipe));
	p->argc = get_cpl_num(cmd_pipe_list);
	p->argv = get_argv_to_cmd_list(p->argc, cmd_pipe_list);
	p->envp = get_envp(envp_list);
	channel->prev_fd = -1;
	p->pid_num = 1;
}

int	set_collabo(t_pipe *p, char **envp)
{
	int	i;

	i = 0;
	p->envp = envp;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			p->path = ft_split(&((envp[i])[5]), ':');
		i++;
	}
	//if (p->path == NULL)
	//{
	//	perror("parsing.c - set pipe");
	//	exit(1);
	//}
	return (1);
}

char	*parse_file(t_pipe p, char **argv)
{
	int		i;
	char	str[2];

	i = 0;
	str[0] = '/';
	str[1] = '\0';
	while (argv[p.operator_cmd ][i])
	{
		if ((8 < argv[p.operator_cmd][i] \
			&& argv[p.operator_cmd][i] < 14) \
			|| argv[p.operator_cmd][i] == 32)
			break ;
		i++;
	}
	return (ft_substr(ft_strjoin(str, argv[p.operator_cmd ]), 0, i));
}
