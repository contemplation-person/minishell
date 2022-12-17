/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:53 by gyim              #+#    #+#             */
/*   Updated: 2022/12/17 16:24:03 by gyim             ###   ########seoul.kr  */
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
		printf("%s ", curr->token);
		curr = curr->next;
	}
	putchar('\n');
}

// int	list_len(t_tnode *head)
// {
// 	int		len;
// 	t_tnode	*curr;

// 	len = 0;
// 	while (curr)
// 	{
// 		len++;
// 		curr = curr->next;
// 	}
// 	return (len);
// }