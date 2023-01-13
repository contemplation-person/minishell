/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:26:48 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 13:40:46 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tnode	*find_op(t_tnode *head)
{
	t_tnode	*target;

	target = check_double_op(head);
	if (target)
		return (target);
	target = check_pipe_op(head);
	if (target)
		return (target);
	return (target);
}

t_tnode	*find_last_node(t_tnode *head)
{
	t_tnode	*curr;

	if (!head)
		return (NULL);
	curr = head;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	add_token_list(t_tnode **head, char *token)
{
	t_tnode	*new_node;
	t_tnode	*last;
	char	*trimmed_token;

	trimmed_token = ft_strtrim(token, " ");
	new_node = make_node(trimmed_token);
	free(trimmed_token);
	last = find_last_node(*head);
	if (!last)
		*head = new_node;
	else
		last->next = new_node;
}

t_tnode	*replace_list(t_tnode **head, t_tnode *prev,
				t_tnode *target, t_tnode *new_list)
{
	t_tnode	*next;
	t_tnode	*last;

	next = target->next;
	if (!prev)
		*head = new_list;
	else
		prev->next = new_list;
	last = find_last_node(new_list);
	last->next = next;
	free(target->token);
	free(target);
	return (last);
}

void	t_tnode_add_list(t_tnode **head, t_tnode *new_tokens)
{
	t_tnode	*curr;

	if (!(*head))
		*head = new_tokens;
	else
	{
		curr = *head;
		while (curr->next)
			curr = curr->next;
		curr->next = new_tokens;
	}
}