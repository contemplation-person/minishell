/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:54:06 by gyim              #+#    #+#             */
/*   Updated: 2022/12/12 16:09:42 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

t_tnode	*check_double_op(t_tnode *head)
{
	int		p_flag;
	t_tnode	*curr;
	t_tnode	*ret;

	curr = head;
	ret = NULL;
	p_flag = 0;
	while (curr)
	{
		if (curr->token[0] == '(')
			p_flag++;
		else if (curr->token[0] == ')')
			p_flag--;
		if (p_flag == 0 && (ft_strncmp(curr->token, "||", 3) == 0
				|| ft_strncmp(curr->token, "&&", 3) == 0))
			ret = curr;
		curr = curr->next;
	}
	if (p_flag != 0)
		return (NULL);
	return (ret);
}

t_tnode	*check_pipe_op(t_tnode *head)
{
	int		p_flag;
	t_tnode	*curr;
	t_tnode	*ret;

	curr = head;
	p_flag = 0;
	ret = NULL;
	while (curr)
	{
		if (curr->token[0] == '(')
			p_flag++;
		else if (curr->token[0] == ')')
			p_flag--;
		if (p_flag == 0 && curr->token[0] == '|')
			ret = curr;
		curr = curr->next;
	}
	if (p_flag != 0)
		return (NULL);
	return (ret);
}

t_tnode	*check_redirect(t_tnode	*head)
{
	int		p_flag;
	t_tnode	*curr;
	t_tnode	*ret;

	curr = head;
	p_flag = 0;
	ret = NULL;
	while (curr)
	{
		if (curr->token[0] == '(')
			p_flag++;
		else if (curr->token[0] == ')')
			p_flag--;
		if (p_flag == 0 && (ft_strncmp(curr->token, "<<", 3) == 0
				|| ft_strncmp(curr->token, "<", 2) == 0
				|| ft_strncmp(curr->token, ">>", 3) == 0
				|| ft_strncmp(curr->token, ">", 2) == 0))
			ret = curr;
		curr = curr->next;
	}
	if (p_flag != 0)
		return (NULL);
	return (ret);
}

t_tnode	*delete_paren(t_tnode *head)
{
	t_tnode	*start;
	t_tnode	*start_prev;
	t_tnode	*last_prev;

	start = head;
	while (1)
	{
		last_prev = last_prev_node(start);
		if (ft_strncmp(start->token, "(", 2) == 0
			&& ft_strncmp(last_prev->next->token, ")", 2) == 0)
		{
			start_prev = start;
			start = start->next;
			free(start_prev->token);
			start_prev->next = NULL;
			free(start_prev);
			free(last_prev->next->token);
			free(last_prev->next);
			last_prev->next = NULL;
		}
		else
			break ;
	}
	// print_list(start);
	return (start);
}
