/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:27:35 by gyim              #+#    #+#             */
/*   Updated: 2023/01/10 19:28:08 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	op_double_and(t_tree_node *node, t_cplist **cmd_list,
				t_env_info_list *env_list)
{

	search_tree(node->left, cmd_list, env_list);
	excute_cmd_pipe_list(cmd_list, env_list);
	printf("%d\n", g_error_code);
	if (g_error_code == 0)
	{
		free_cmd_pipe_list(cmd_list);
		*cmd_list = init_cmd_pipe_lists();
		search_tree(node->right, cmd_list, env_list);
		excute_cmd_pipe_list(cmd_list, env_list);
	}
	return (g_error_code);
}

int	op_double_or(t_tree_node *node, t_cplist **cmd_list,
				t_env_info_list *env_list)
{
	t_cplist	*new_cmd_list;

	search_tree(node->left, cmd_list, env_list);
	excute_cmd_pipe_list(cmd_list, env_list);
	if (g_error_code != 0)
	{
		free_cmd_pipe_list(cmd_list);
		*cmd_list = init_cmd_pipe_lists();
		new_cmd_list = init_cmd_pipe_lists();
		search_tree(node->right, cmd_list, env_list);
		excute_cmd_pipe_list(cmd_list, env_list);
	}
	return (g_error_code);
}
