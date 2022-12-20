/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:16 by gyim              #+#    #+#             */
/*   Updated: 2022/12/20 15:40:07 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

int	excute_cmd(t_tnode *cmd_list, t_env_info_list *env_list)
{
	t_tnode	*curr;
	char	**cmd;

	curr = cmd_list;
	cmd = get_cmd(cmd_list);
	find_cmd(cmd, env_list);
	return (0);
}

int	get_cmd_list_len(t_tnode *head)
{
	int		len;
	t_tnode	*curr;

	len = 0;
	curr = head;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

char	**get_cmd(t_tnode *head)
{
	int		len;
	t_tnode	*curr;
	char	**cmd;
	int		i;

	len = get_cmd_list_len(head);
	cmd = malloc(sizeof(char *) * (len + 1));
	curr = head;
	i = 0;
	while (curr)
	{
		cmd[i++] = ft_strdup(curr->token);
		curr = curr->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

int	find_cmd(char **cmd, t_env_info_list *env_list)
{
	char	**path;

	path = get_path(env_list);
	env_list = NULL;
	cmd = NULL;
	// execve("/bin/ls", test, NULL);
	free_path(path);
	return (0);
}

