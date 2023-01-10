/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:06:38 by gyim              #+#    #+#             */
/*   Updated: 2023/01/10 15:19:53 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	search_tree(t_tree_node *node, t_cplist *cmd_list,
	t_env_info_list *envp_list)
{
	if (!node->left && !node->right)
		excute_list_add(cmd_list, node->words, envp_list);
	else
	{
		if (node->left)
			search_tree(node->left, cmd_list, envp_list);
		if (node->right)
			search_tree(node->right, cmd_list, envp_list);
	}
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

void	excute_list_add(t_cplist *cmd_list, t_tnode *cmds,
			t_env_info_list *env_list)
{
	t_rnode	*new_redirection;

	env_list = NULL;
	new_redirection = get_redirection(cmds);
	rd_list_add(&cmd_list->rd_head, new_redirection);
	cmd_list_add(&cmd_list->cmd_head, cmds);
}

t_cplist	*init_cmd_pipe_lists(void)
{
	t_cplist	*new_list;

	new_list = malloc(sizeof(t_cplist));
	if (!new_list)
		return (NULL);
	new_list->cmd_head = NULL;
	new_list->rd_head = NULL;
	return (new_list);
}
