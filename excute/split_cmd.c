/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:21:26 by gyim              #+#    #+#             */
/*   Updated: 2023/01/14 14:49:10 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

char	**split_cmd(char *cmd)
{
	char			**cmds;
	t_tlist_info	*token_list;

	token_list = split_input(cmd);
	remove_all_token_quote(&token_list->head);
	cmds = all_token_to_cmds(&token_list->head);
	free_tlist(token_list->head);
	free(token_list);
	return (cmds);
}

void	remove_all_token_quote(t_tnode **head)
{
	t_tnode	*curr;
	char	*removed_quote;

	curr = *head;
	while (curr)
	{
		removed_quote = remove_token_quote(curr->token);
		free(curr->token);
		curr->token = removed_quote;
		curr = curr->next;
	}
}

char	**all_token_to_cmds(t_tnode **head)
{
	t_tnode	*curr;
	char	**ret;
	int		len;
	int		i;

	len = get_cmd_list_len(*head);
	ret = ft_calloc(sizeof(char *), len + 1);
	curr = *head;
	i = 0;
	while (curr)
	{
		if (!is_parenthesis(curr->token))
			ret[i++] = ft_strdup(curr->token);
		curr = curr->next;
	}
	return (ret);
}