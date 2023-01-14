/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:21:32 by gyim              #+#    #+#             */
/*   Updated: 2023/01/14 11:02:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parsing_excute(char *user_input, t_fds *fds, t_env_info_list *env_list)
{
	t_tlist_info	*word_list;

	if (user_input[0] == '\0')
		return (0);
	word_list = split_input(user_input);
	if (!word_list->head)
		return (0);
	if (valid_check(word_list->head) == -1)
	{
		del_list(word_list);
		g_error_code = 2;
		return (g_error_code);
	}
	multiple_cmds_excute(word_list, fds, env_list);
	free(word_list);
	word_list = NULL;
	return (0);
}

t_tree_node	*parser(t_tlist_info *list)
{
	t_tree_node	*root;

	root = make_tree(list->head);
	if (!root)
		return (NULL);
	return (root);
}

void	multiple_cmds_excute(t_tlist_info *word_list, t_fds *fds,
			t_env_info_list *env_list)
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
			excute_all(cmd_pipe_lists, fds, env_list);
		free_cmd_pipe_list(&cmd_pipe_lists);
		del_tree(root);
		free(root);
	}
}
