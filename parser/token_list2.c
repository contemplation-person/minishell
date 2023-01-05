/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:53 by gyim              #+#    #+#             */
/*   Updated: 2023/01/05 16:29:06 by juha             ###   ########seoul.kr  */
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

void	print_list(t_tnode *head)
{
	t_tnode	*curr;

	curr = head;
	while (curr)
	{
		printf("[%s]", curr->token);
		curr = curr->next;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	list_add(t_tlist_info *list, char *str)
{
	t_tnode	*new_node;
	t_tnode	*last_node;

	new_node = make_node(str);
	if (!new_node)
		return ;
	last_node = lst_last(list);
	if (!last_node)
		list->head = new_node;
	else
		last_node->next = new_node;
}

void	del_list(t_tlist_info *list)
{
	t_tnode	*curr;
	t_tnode	*next;

	curr = list->head;
	while (curr)
	{
		next = curr->next;
		free(curr->token);
		free(curr);
		curr = next;
	}
	free(list);
	list = NULL;
}
