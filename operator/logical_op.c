/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:27:35 by gyim              #+#    #+#             */
/*   Updated: 2023/01/12 13:26:09 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	op_double_and(t_tree_node *node, t_cplist **cmd_list,
				t_fds *fds, t_env_info_list *env_list)
{

	search_tree(node->left, cmd_list, fds, env_list);
	excute_all(*cmd_list, fds, env_list);
	if (g_error_code == 0)
	{
		free_cmd_pipe_list(cmd_list);
		search_tree(node->right, cmd_list, fds, env_list);
		excute_all(*cmd_list, fds, env_list);
	}
	return (g_error_code);
}

int	op_double_or(t_tree_node *node, t_cplist **cmd_list,
				t_fds *fds, t_env_info_list *env_list)
{

	search_tree(node->left, cmd_list, fds, env_list);
	excute_all(*cmd_list, fds, env_list);
	if (g_error_code != 0)
	{
		free_cmd_pipe_list(cmd_list);
		search_tree(node->right, cmd_list, fds, env_list);
		excute_all(*cmd_list, fds, env_list);
	}
	return (g_error_code);
}
