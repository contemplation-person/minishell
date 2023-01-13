/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:34:58 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 16:25:48 by gyim             ###   ########seoul.kr  */
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

void	multiple_cmds_excute(t_tlist_info *word_list, t_fds *fds, t_env_info_list *env_list)
{
	t_tree_node			*root;
	t_cplist			*cmd_pipe_lists;

	root = parser(word_list);
	cmd_pipe_lists = NULL;
	if (root)
	{
		if (tree_valid_check(root) != -1)
			search_tree(root, &cmd_pipe_lists, fds, env_list);
		if (cmd_pipe_lists != NULL)
		{
			write(2, "123\n", 4);
			excute_all(cmd_pipe_lists, fds, env_list);
		}
		free_cmd_pipe_list(&cmd_pipe_lists);
		del_tree(root);
		free(root);
	}
}
