/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:16:04 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 09:51:18 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

t_cplist	*new_cplist(void)
{
	t_cplist	*ret;

	ret = malloc(sizeof(t_cplist));
	if (!ret)
		return (NULL);
	ret->cmd = NULL;
	ret->rd_head = NULL;
	ret->next = NULL;
	return (ret);
}

char	*get_cplist_cmd(t_tnode *cmds, t_env_info_list *env_list)
{
	char	*ret;

	expansion(cmds, env_list);
 	retokenize(cmds);
 	// quote_remove(cmds);

	ret = merge_token(cmds);
	return (ret);
}

int	cplist_len(t_cplist *cmd_pipe_list)
{
	int			len;
	t_cplist	*curr;

	len = 0;
	curr = cmd_pipe_list;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
