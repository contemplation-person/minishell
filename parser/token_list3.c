/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:22:43 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 09:19:31 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

t_tnode	*find_last_node(t_tnode *head)
{
	t_tnode	*curr;

	if (!head)
		return (NULL);
	curr = head;
	printf("%p\n", curr->next);
	while (curr->next)
		curr = curr->next;
	return (curr);
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

t_tnode	*find_prev(t_tnode *head, t_tnode *target)
{
	t_tnode	*curr;

	curr = head;
	while (curr->next)
	{
		if (curr->next == target)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}