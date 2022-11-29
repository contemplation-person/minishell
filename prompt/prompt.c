/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:29:21 by gyim              #+#    #+#             */
/*   Updated: 2022/11/29 18:32:53 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "split_input.h"

void	print_list(t_tlist_info *list);
int	main(int argc, char *argv[])
{
	char			*user_input;
	t_tlist_info	*word_list;

	if (argc != 1)
	{
		write(2, "no argument needed\n", 19);
		return (0);
	}
	while (1)
	{
		user_input = readline("minishell$ ");
		word_list = split_input(user_input);
		print_list(word_list);
		free(user_input);
	}
	return (0);
}

void	print_list(t_tlist_info *list)
{
	t_tnode	*curr;

	if (!list->head)
	{
		printf("empty\n");
		return ;
	}
	curr = list->head;
	while (curr)
	{
		printf("%s ", curr->token);
		curr = curr->next;
	}
	printf("\n");
}
