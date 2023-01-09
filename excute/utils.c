/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:27:17 by gyim              #+#    #+#             */
/*   Updated: 2023/01/09 19:36:49 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	free_cmd_pipe_list(t_cplist **cmd_pipe_lists)
{
	free_red((*cmd_pipe_lists)->rd_head);
	free_cmd_list((*cmd_pipe_lists)->cmd_head);
	free((*cmd_pipe_lists)->rd_head);
	free((*cmd_pipe_lists)->cmd_head);
	free(*cmd_pipe_lists);
}

void	free_cmd_list(t_cmd_node *head)
{
	t_cmd_node	*curr;
	t_cmd_node	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		free_cmd(curr->cmd);
		curr = next;
	}
}
