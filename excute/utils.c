/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:27:17 by gyim              #+#    #+#             */
/*   Updated: 2023/01/11 10:01:19 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	free_cmd_pipe_list(t_cplist **cmd_pipe_lists)
{
	t_cplist	*curr;
	t_cplist	*next;

	curr = *cmd_pipe_lists;
	while (curr)
	{
		next = curr->next;
		free(curr->cmd);
		free_red(curr->rd_head);
		curr = next;
	}
}

char	*merge_token(t_tnode *head)
{
	t_tnode	*curr;
	char	*ret;
	char	*temp1;
	char	*temp2;

	ret = ft_strdup(head->token);
	curr = head->next;
	while (curr)
	{
		if (curr->next && is_redirection(curr->token))
		{
			curr = curr->next->next;
			continue ;
		}
		temp1 = ft_strjoin(" ", curr->token);
		temp2 = ft_strjoin(ret, temp1);
		free(ret);
		free(temp1);
		ret = temp2;
		curr = curr->next;
	}
	return (ret);
}
