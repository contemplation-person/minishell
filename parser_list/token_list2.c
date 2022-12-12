/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:53 by gyim              #+#    #+#             */
/*   Updated: 2022/12/12 16:05:35 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tnode	*last_prev_node(t_tnode *head)
{
	t_tnode	*curr;
	t_tnode	*prev;

	curr = head;
	prev = NULL;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	return (prev);
}
void	free_list(t_tnode *head)
{
	t_tnode	*curr;
	t_tnode	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr->token);
		curr->token = NULL;
		free(curr);
		curr = next;
	}
}
