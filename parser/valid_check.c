/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:52:44 by gyim              #+#    #+#             */
/*   Updated: 2022/12/12 19:43:54 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	valid_check(t_tnode *head)
{
	t_tnode	*curr;

	curr = head;
	while (curr)
	{
		if (quote_check(curr->token) == -1)
			return (-1);
		curr = curr->next;
	}
	return (paren_check(head));
}

int	quote_check(char *token)
{
	int	i;
	int	in_quote;

	in_quote = 0;
	i = 0;
	while (token[i])
	{
		if (in_quote == 0 && token[i] == '\'')
			in_quote = 1;
		else if (in_quote == 0 && token[i] == '\"')
			in_quote = 2;
		else if (in_quote == 1 && token[i] == '\'')
			in_quote = 0;
		else if (in_quote == 2 && token[i] == '\"')
			in_quote = 0;
		i++;
	}
	if (in_quote != 0)
	{
		printf("quote not paired\n");
		return (-1);
	}
	return (0);
}

int	paren_check(t_tnode *head)
{
	t_tnode	*curr;
	int		in_paren;

	in_paren = 0;
	curr = head;
	while (curr)
	{
		if (curr->token[0] == '(')
			in_paren++;
		else if (curr->token[0] == ')')
			in_paren--;
		if (in_paren < 0)
			return (-1);
		curr = curr->next;
	}
	if (in_paren != 0)
	{
		printf("parenthesis not equal\n");
		return (-1);
	}
	return (0);
}