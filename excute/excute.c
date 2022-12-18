/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:16 by gyim              #+#    #+#             */
/*   Updated: 2022/12/18 12:02:48 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

int	excute_cmd(t_tnode *cmd_list)
{
	t_tnode	*curr;
	char	**cmd;

	curr = cmd_list;
	cmd = get_cmd(cmd_list);
	find_cmd(cmd);
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

int	find_cmd(char **cmd)
{
	char	*test[2];

	test[0] = "ls";
	test[1] = NULL;
	execve("/bin/ls", test, NULL);
	return (0);
}