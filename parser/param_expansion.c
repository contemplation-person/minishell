/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:08 by gyim              #+#    #+#             */
/*   Updated: 2023/01/06 18:21:30 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	expansion(t_tnode *head, t_env_info_list *env_list)
{
	t_tnode	*curr;
	char	*p_expanded;
	char	*a_expanded;

	curr = head;
	while (curr)
	{
		p_expanded = p_token_expansion(curr->token, env_list);
		a_expanded = asterisk(p_expanded);
		if (!a_expanded)
			a_expanded = ft_strdup("");
		free(curr->token);
		free(p_expanded);
		curr->token = NULL;
		curr->token = a_expanded;
		curr = curr->next;
	}
	return (0);
}

void	retokenize(t_tnode	*head)
{
	t_tnode	*curr;
	t_tnode	*prev;
	t_tnode	*tokened_list;

	prev = NULL;
	curr = head;
	while (curr)
	{
		tokened_list = split_token(curr->token);
		if (!tokened_list)
			add_token_list(&tokened_list, "");
		if (ft_strncmp (tokened_list->token, curr->token,
				ft_strlen(tokened_list->token) + 1) != 0)
			curr = replace_list(&head, prev, curr, tokened_list);
		else
			free_list(tokened_list);
		prev = curr;
		curr = curr->next;
	}
}

void	skip_d_quote(char *token, int *index)
{
	(*index)++;
	while (token[*index] && token[(*index)] != '\"')
		(*index)++;
	(*index)++;
}

t_tnode	*split_token(char *token)
{
	int		i;
	int		start;
	char	*sub_token;
	t_tnode	*head;

	start = 0;
	i = 0;
	head = NULL;
	while (token[i])
	{
		if (token[i] == '\'')
			skip_s_quote(token, &i);
		else if (token[i] == '\"')
			skip_d_quote(token, &i);
		if (token[i + 1] == ' ' || token[i + 1] == '\0')
		{
			sub_token = ft_substr(token, start, i - start + 1);
			add_token_list(&head, sub_token);
			free(sub_token);
			start = i + 1;
		}
		i++;
	}
	return (head);
}
