/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:00:54 by gyim              #+#    #+#             */
/*   Updated: 2022/12/10 19:07:40 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tlist_info	*tlist_init(void)
{
	t_tlist_info	*list_info;

	list_info = malloc(sizeof(t_tlist_info));
	if (!list_info)
		return (NULL);
	list_info->head = NULL;
	list_info->cnt = 0;
	return (list_info);
}

t_tnode	*make_node(char *str)
{
	t_tnode	*new_node;

	new_node = malloc(sizeof(t_tnode));
	if (!new_node)
		return (NULL);
	new_node->token = ft_strdup(str);
	new_node->next = NULL;
	if (!new_node->token)
	{
		free(new_node);
		new_node = NULL;
		return (NULL);
	}
	return (new_node);
}

t_tnode	*lst_last(t_tlist_info *list_info)
{
	t_tnode	*curr_node;

	curr_node = list_info->head;
	if (!curr_node)
		return (NULL);
	while (curr_node->next)
		curr_node = curr_node->next;
	return (curr_node);
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
	t_tnode	*node;
	t_tnode	*next;

	node = list->head;
	while (node)
	{
		next = node->next;
		free(node->token);
		node->token = NULL;
		free(node);
		node = NULL;
		node = next;
	}
	free(list);
	list = NULL;
}

void	free_list(t_tnode *head)
{
	t_tnode	*curr;
	t_tnode	*next;

	printf("free list: ");
	printf("head : %s\n", head->token);
	curr = head;
	while (curr)
	{
		printf("%s ", curr->token);
		next = curr->next;
		free(curr->token);
		curr->token = NULL;
		free(curr);
		curr = next;
	}
	putchar ('\n');
}
