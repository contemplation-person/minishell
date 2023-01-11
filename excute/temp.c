/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:59:03 by gyim              #+#    #+#             */
/*   Updated: 2023/01/11 14:09:19 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	print_cmd_pipe_list(t_cplist *list)
{
	t_cplist	*curr;
	t_rnode		*rd_curr;

	curr = list;
	while (curr)
	{
		printf("[%s]\n", curr->cmd);
		rd_curr = curr->rd_head;
		while (rd_curr)
		{
			printf("%d %s\n", rd_curr->redirection, rd_curr->file);
			rd_curr = rd_curr->next;
		}
		curr = curr->next;
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
	printf("%d %s\n", i, cmd[i]);
}
