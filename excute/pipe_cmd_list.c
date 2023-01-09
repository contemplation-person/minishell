/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:06:38 by gyim              #+#    #+#             */
/*   Updated: 2023/01/09 19:22:01 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	search_tree(t_tree_node *node, t_cplist *cmd_list,
	t_env_info_list *envp_list)
{
	if (!node->left && !node->right)
		excute_list_add(cmd_list, node->words);
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

void	cmd_list_add(t_cmd_node	**head, char **cmd)
{
	t_cmd_node	*new_node;
	t_cmd_node	*curr;

	new_node = malloc(sizeof(t_cmd_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->cmd = cmd;
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


void	excute_list_add(t_cplist *cmd_list, t_tnode *cmds)
{
	t_rnode	*new_redirection;
	char	**new_cmd;

	new_redirection = get_redirection(cmds);
	rd_list_add(&cmd_list->rd_head, new_redirection);
	new_cmd = get_cmd(cmds);
	cmd_list_add(&cmd_list->cmd_head, new_cmd);
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
