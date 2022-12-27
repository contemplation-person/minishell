/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:34:58 by gyim              #+#    #+#             */
/*   Updated: 2022/12/27 11:00:37 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	multiple_cmds_check(t_tlist_info *word_list)
{
	t_tnode	*curr;

	curr = word_list->head;
	while (curr)
	{
		if (curr->token[0] == '|')
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	one_cmd_excute(t_tree_node *root, t_env_info_list *env_list)
{
	t_fds	fds;
	pid_t	pid;

	fds.in_fd = dup(STDIN_FILENO);
	fds.out_fd = dup(STDOUT_FILENO);
	printf("one_cmds\n");
}
