/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:34:58 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 18:53:34 by gyim             ###   ########seoul.kr  */
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

void	one_cmd_excute(t_tlist_info *word_list, t_env_info_list *env_list)
{
	t_fds		fds;
	t_tree_node	*root;

	root = parser(word_list);
	if (root)
	{
		fds.in_fd = dup(STDIN_FILENO);
		fds.out_fd = dup(STDOUT_FILENO);
		if (tree_valid_check(root) != -1)
		{
			search_tree(root, &fds, env_list);
			while (waitpid(-1, NULL, WNOHANG) != -1)
				;
		}
		del_tree(root);
		free(root);
	}
}

void	multiple_cmds_excute(t_tlist_info *word_list, t_env_info_list *env_list)
{
	t_fds		fds;
	t_tree_node	*root;

	root = parser(word_list);
	fds.in_fd = dup(STDIN_FILENO);
	fds.out_fd = dup(STDOUT_FILENO);
	printf("%d %d\n", fds.in_fd, fds.out_fd);
	if (root)
	{
		if (tree_valid_check(root) != -1)
		{
			search_tree(root, &fds, env_list);
			wait(0);
		}
		del_tree(root);
		free(root);
	}
}
