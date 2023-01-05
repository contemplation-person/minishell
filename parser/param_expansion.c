/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:08 by gyim              #+#    #+#             */
/*   Updated: 2023/01/05 13:26:07 by gyim             ###   ########seoul.kr  */
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
		p_expanded = p_expansion(curr->token, env_list);
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
