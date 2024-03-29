/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:16 by gyim              #+#    #+#             */
/*   Updated: 2023/01/17 16:38:14 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_cmd_num(t_tnode *cmd_list)
{
	int		i;
	t_tnode	*temp;

	i = 0;
	temp = cmd_list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

char	**get_argv_to_cmd_list(int cnt_cmd, t_cplist *cmd_list)
{
	char		**ret;
	int			i;
	t_cplist	*temp;

	temp = cmd_list;
	i = 0;
	ret = ft_calloc(cnt_cmd + 1, sizeof(char *));
	if (!ret)
		exit(1);
	while (i < cnt_cmd)
	{
		if (!temp->cmd)
			break ;
		ret[i] = ft_strdup(temp->cmd);
		if (!(ret[i]))
			exit(1);
		temp = temp->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**get_envp(t_env_info_list	*envp_list)
{
	int			i;
	t_env_info	*temp;
	char		**ret;

	temp = envp_list->env_info;
	ret = ft_calloc(envp_list->cnt + 1, sizeof(char *));
	i = 0;
	while (temp)
	{
		ret[i] = envp_node_to_str(temp);
		if (!ret)
			exit(1);
		temp = temp->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
