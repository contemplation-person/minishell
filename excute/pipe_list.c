/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:16:04 by gyim              #+#    #+#             */
/*   Updated: 2023/01/17 16:33:41 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

t_cplist	*new_cplist(void)
{
	t_cplist	*ret;

	ret = malloc(sizeof(t_cplist));
	if (!ret)
		return (NULL);
	ret->cmd = NULL;
	ret->rd_head = NULL;
	ret->next = NULL;
	return (ret);
}

char	*get_cplist_cmd(t_tnode *cmds, t_env_info_list *env_list)
{
	char	*ret;
	t_tnode	*cmd_token;

	cmd_token = get_cmd_tnode(cmds);
	if (!cmd_token)
		return (NULL);
	expansion(cmd_token, env_list);
	retokenize(cmd_token);
	ret = merge_token(cmd_token);
	free_tlist(cmd_token);
	return (ret);
}

int	cplist_len(t_cplist *cmd_pipe_list)
{
	int			len;
	t_cplist	*curr;

	len = 0;
	curr = cmd_pipe_list;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

t_tnode	*get_cmd_tnode(t_tnode *head)
{
	t_tnode	*ret;
	t_tnode	*curr;

	curr = head;
	ret = NULL;
	while (curr)
	{
		if (is_redirection(curr->token))
			curr = curr->next->next;
		else
		{
			add_tlist(&ret, curr->token);
			curr = curr->next;
		}
	}
	return (ret);
}

void	add_tlist(t_tnode **head, char *token)
{
	t_tnode	*last;
	t_tnode	*new_node;

	last = find_last_node(*head);
	new_node = make_node(token);
	if (!last)
		*head = new_node;
	else
		last->next = new_node;
}
