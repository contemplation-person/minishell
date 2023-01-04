/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:11:04 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 19:39:48 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

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
		if (curr->next && is_redirection(curr->token))
			curr = curr->next->next;
		else
		{
			cmd[i++] = ft_strdup(curr->token);
			curr = curr->next;
		}
	}
	cmd[i] = NULL;
	return (cmd);
}

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		cmd[i] = NULL;
		i++;
	}
	free(cmd);
	cmd = NULL;
}

void	cmd_path_check(char **path, char **cmd,
				t_env_info_list *envp_list)
{
	int		i;
	char	*cmd_path;
	char	**envp;

	i = 0;
	envp = envp_list_to_arr(envp_list);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd[0]);
		execve(cmd_path, cmd, envp);
		i++;
	}
	execve(cmd[0], cmd, envp);
}
