/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:04:52 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 08:21:11 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	search_tree(t_tree_node *node, t_cplist **cmd_list,
	t_fds *fds, t_env_info_list *envp_list)
{
	if (node->op && ft_strncmp(node->op->token, "&&", 3) == 0)
		op_double_and(node, cmd_list, fds, envp_list);
	else if (node->op && ft_strncmp(node->op->token, "||", 3) == 0)
		op_double_or(node, cmd_list, fds, envp_list);
	else if (node->op && ft_strncmp(node->op->token, "|", 2) == 0)
	{
		search_tree(node->left, cmd_list, fds, envp_list);
		search_tree(node->right, cmd_list, fds, envp_list);
	}
	else
		excute_list_add(cmd_list, node->words, envp_list);
}

void	excute_list_add(t_cplist **cmd_list, t_tnode *cmds,
			t_env_info_list *env_list)
{
	t_cplist	*new_node;
	t_cplist	*curr;

	new_node = new_cplist();
	get_redirection(&new_node->rd_head, cmds);
	new_node->cmd = get_cplist_cmd(cmds, env_list);
	if (!*cmd_list)
		*cmd_list = new_node;
	else
	{
		curr = *cmd_list;
		while (curr->next)
			curr = curr->next;
		curr->next = new_node;
	}
}

int	op_double_and(t_tree_node *node, t_cplist **cmd_list,
				t_fds *fds, t_env_info_list *env_list)
{
	search_tree(node->left, cmd_list, fds, env_list);
	excute_all(*cmd_list, fds, env_list);
	free_cmd_pipe_list(cmd_list);
	if (g_error_code == 0)
	{
		free_cmd_pipe_list(cmd_list);
		search_tree(node->right, cmd_list, fds, env_list);
		excute_all(*cmd_list, fds, env_list);
		free_cmd_pipe_list(cmd_list);
		return (g_error_code);
	}
	return (g_error_code);
}

int	op_double_or(t_tree_node *node, t_cplist **cmd_list,
				t_fds *fds, t_env_info_list *env_list)
{

	search_tree(node->left, cmd_list, fds, env_list);
	excute_all(*cmd_list, fds, env_list);
	free_cmd_pipe_list(cmd_list);
	if (g_error_code != 0)
	{
		free_cmd_pipe_list(cmd_list);
		search_tree(node->right, cmd_list, fds, env_list);
		excute_all(*cmd_list, fds, env_list);
		free_cmd_pipe_list(cmd_list);
		return (g_error_code);
	}
	return (g_error_code);
}
