/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:34:58 by gyim              #+#    #+#             */
/*   Updated: 2023/01/09 19:28:46 by gyim             ###   ########seoul.kr  */
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
	t_tree_node			*root;
	t_cplist			*cmd_pipe_lists;

	root = parser(word_list);
	cmd_pipe_lists = init_cmd_pipe_lists();
	if (root)
	{
		if (tree_valid_check(root) != -1)
			search_tree(root, cmd_pipe_lists, env_list);
		print_cmd_pipe_list(cmd_pipe_lists);
		free_cmd_pipe_list(&cmd_pipe_lists);
		del_tree(root);
		free(root);
	}
}
