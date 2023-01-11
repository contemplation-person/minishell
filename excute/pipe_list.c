/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:06:38 by gyim              #+#    #+#             */
/*   Updated: 2023/01/11 13:28:06 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	search_tree(t_tree_node *node, t_cplist **cmd_list,
	t_env_info_list *envp_list)
{
	if (node->op && ft_strncmp(node->op->token, "&&", 3) == 0)
		op_double_and(node, cmd_list, envp_list);
	else if (node->op && ft_strncmp(node->op->token, "||", 3) == 0)
		op_double_or(node, cmd_list, envp_list);
	else if (node->op && ft_strncmp(node->op->token, "|", 2) == 0)
	{
		search_tree(node->left, cmd_list, envp_list);
		search_tree(node->right, cmd_list, envp_list);
	}
	else
		excute_list_add(cmd_list, node->words, envp_list);
}

void	rd_list_add(t_rnode **head, t_rnode *target)
{
	t_rnode	*curr;

	if (!*head)
		*head = target;
	else
	{
		curr = *head;
		while (curr->next)
			curr = curr->next;
		curr->next = target;
	}
}

void	cmd_list_add(t_tnode **head, t_tnode *node)
{
	t_tnode	*new_node;
	t_tnode	*curr;

	new_node = malloc(sizeof(t_tnode));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->token = merge_token(node);
	if (!*head)
		*head = new_node;
	else
	{
		curr = *head;
		while (curr->next)
			curr = curr->next;
		curr->next = new_node;
	}
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

t_cplist	*init_cmd_pipe_lists(void)
{
	t_cplist	*new_list;

	new_list = malloc(sizeof(t_cplist));
	if (!new_list)
		return (NULL);
	new_list->cmd = NULL;
	new_list->rd_head = NULL;
	new_list->next = NULL;
	return (new_list);
}
