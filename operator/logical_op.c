/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:27:35 by gyim              #+#    #+#             */
/*   Updated: 2022/12/31 21:14:54 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	op_double_and(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	search_tree(node->left, fd_info, env_list);
	if ((WEXITSTATUS(g_error_code)) == 0)
		search_tree(node->right, fd_info, env_list);
	return (g_error_code);
}

int	op_double_or(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	search_tree(node->left, fd_info, env_list);
	if (WEXITSTATUS(g_error_code) != 0)
		search_tree(node->right, fd_info, env_list);
	return (g_error_code);
}
