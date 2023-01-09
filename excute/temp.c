/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:59:03 by gyim              #+#    #+#             */
/*   Updated: 2023/01/09 19:23:59 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	print_cmd_pipe_list(t_cplist *list)
{
	t_cmd_node	*cmd_curr;
	t_rnode		*rd_curr;

	cmd_curr = list->cmd_head;
	printf("cmds : \n");
	while (cmd_curr)
	{
		print_cmds(cmd_curr->cmd);
		cmd_curr = cmd_curr->next;
	}
	printf("redirections : \n");
	rd_curr = list->rd_head;
	while (rd_curr)
	{
		printf("%d %s\n", rd_curr->redirection, rd_curr->file);
		rd_curr = rd_curr->next;
	}
}

void	print_cmds(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		printf("%d %s\n",i, cmd[i]);
		i++;
	}
}
