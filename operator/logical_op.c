/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:27:35 by gyim              #+#    #+#             */
/*   Updated: 2022/12/30 15:03:43 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	op_double_and(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int	exit_code;

	printf("double and\n");
	exit_code = search_tree(node->left, fd_info, env_list);
	if (WEXITSTATUS(exit_code) == 0)
		exit_code = search_tree(node->right, fd_info, env_list);
	return (exit_code);
}

int	op_double_or(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	int	exit_code;

	printf("double or\n");
	exit_code = search_tree(node->left, fd_info, env_list);
	if (WEXITSTATUS(exit_code) != 0)
		exit_code = search_tree(node->right, fd_info, env_list);
	return (exit_code);
}
