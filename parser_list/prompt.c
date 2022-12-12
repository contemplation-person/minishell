/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:29:21 by gyim              #+#    #+#             */
/*   Updated: 2022/12/12 19:51:48 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(int argc, char *argv[])
{
	char			*user_input;
	t_tlist_info	*word_list;
	t_node			*root;

	if (argc != 1)
	{
		write(2, "no argument needed\n", 19);
		return (0);
	}
	while (1)
	{
		user_input = readline("minishell$ ");
		if (ft_strncmp(user_input, "exit", 5) == 0)
			break ;
		word_list = split_input(user_input);
		if (valid_check(word_list->head) == -1)
		{
			del_list(word_list);
			return (0);
		}
		root = parser(word_list);
		excute_tree(root);
		del_list(word_list);
		del_tree(root);
		free(root);
		word_list = NULL;
		free(user_input);
		user_input = NULL;
	}
	free(user_input);
	system("leaks a.out");
	return (0);
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
