/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:27:17 by gyim              #+#    #+#             */
/*   Updated: 2023/01/10 14:12:13 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	free_cmd_pipe_list(t_cplist **cmd_pipe_lists)
{
	free_red((*cmd_pipe_lists)->rd_head);
	free_list((*cmd_pipe_lists)->cmd_head);
	free(*cmd_pipe_lists);
}

char	*merge_token(t_tnode *head)
{
	t_tnode	*curr;
	char	*ret;
	char	*temp1;
	char	*temp2;

	curr = head;
	ret = ft_strdup("");
	while (curr)
	{
		temp1 = ft_strjoin(" ", curr->token);
		temp2 = ft_strjoin(ret, temp1);
		free(ret);
		free(temp1);
		ret = temp2;
		curr = curr->next;
	}
	return (ret);
}
