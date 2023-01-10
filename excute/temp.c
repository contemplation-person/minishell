/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:59:03 by gyim              #+#    #+#             */
/*   Updated: 2023/01/10 13:50:32 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	print_cmd_pipe_list(t_cplist *list)
{
	t_tnode		*cmd_curr;
	t_rnode		*rd_curr;

	cmd_curr = list->cmd_head;
	printf("cmds : \n");
	while (cmd_curr)
	{
		printf("%s ", cmd_curr->token);
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
