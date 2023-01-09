/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:34:58 by gyim              #+#    #+#             */
/*   Updated: 2023/01/09 10:22:59 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	multiple_cmds_check(t_tlist_info *word_list)
{
	t_tnode	*curr;
	int		ret;

	ret = 0;
	curr = word_list->head;
	while (curr)
	{
		if (curr->token[0] == '|')
			ret = 1;
		curr = curr->next;
	}
	return (ret);
}

void	multiple_cmds_excute(t_tlist_info *word_list, t_env_info_list *env_list)
{
	t_fds		fds;
	t_tree_node	*root;
	int			pid;
	int			status;

	root = parser(word_list);
	fds.in_fd = dup(STDIN_FILENO);
	fds.out_fd = dup(STDOUT_FILENO);
	fds.stdin_fd = dup(STDIN_FILENO);
	fds.stdout_fd = dup(STDOUT_FILENO);
	if (root)
	{
		if (tree_valid_check(root) != -1)
		{
			pid = search_tree(root, &fds, env_list);
			if (pid != -999)
			{
				waitpid(pid, &status, 0);
				g_error_code = WEXITSTATUS(status);
			}
		}
		del_tree(root);
		free(root);
	}
	close(fds.stdin_fd);
	close(fds.stdout_fd);
}
