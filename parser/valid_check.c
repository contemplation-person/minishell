/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:52:44 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 08:00:51 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#define PAREN_ERROR	"unexpedted token ')' near grammer error\n"
#define UNEXPECTED_TOKEN "unexpected token\n"

int	valid_check(t_tnode *head)
{
	if (quote_check(head) == -1)
		return (-1);
	if (paren_check(head) == -1)
	{
		write(2, PAREN_ERROR, ft_strlen(PAREN_ERROR));
		return (-1);
	}
	if (grammar_check(head) == -1)
	{
		write(2, UNEXPECTED_TOKEN, ft_strlen(UNEXPECTED_TOKEN));
		return (-1);
	}
	return (0);
}

int	in_quote_check(char ch, int in_quote)
{
	if (in_quote == 0 && ch == '\'')
		return (1);
	else if (in_quote == 0 && ch == '\"')
		return (2);
	else if (in_quote == 1 && ch == '\'')
		return (0);
	else if (in_quote == 2 && ch == '\"')
		return (0);
	return (in_quote);
}

int	quote_check(t_tnode *head)
{
	int		i;
	int		in_quote;
	t_tnode	*curr;

	in_quote = 0;
	i = 0;
	curr = head;
	while (curr)
	{
		i = 0;
		while (curr->token[i])
		{
			in_quote = in_quote_check(curr->token[i], in_quote);
			i++;
		}
		if (in_quote != 0)
		{
			ft_printf("quote not paired\n");
			return (-1);
		}
		curr = curr->next;
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
		if (curr->token[0] == '(' && curr->next && curr->next->token[0] == ')')
			return (-1);
		if (in_paren < 0)
			return (-1);
		curr = curr->next;
	}
	if (in_paren != 0)
	{
		write(2, "parenthesis not equal\n", 22);
		return (-1);
	}
	return (0);
}

int	grammar_check(t_tnode *head)
{
	t_tnode	*curr;
	t_tnode	*prev;

	if (!head)
		return (0);
	prev = head;
	curr = head->next;
	if (is_double_op(head->token))
		return (-1);
	while (curr)
	{
		if (op_valid_check(prev, curr) == -1)
			return (-1);
		prev = curr;
		curr = curr->next;
	}
	if (op_valid_check(prev, curr) == -1)
		return (-1);
	return (0);
}
