/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:11:04 by gyim              #+#    #+#             */
/*   Updated: 2023/01/03 13:31:13 by gyim             ###   ########seoul.kr  */
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
