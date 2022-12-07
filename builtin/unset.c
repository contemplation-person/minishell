/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:41:07 by juha              #+#    #+#             */
/*   Updated: 2022/12/07 20:39:46 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	del(void *str)
{
	free(str);
}

static 

t_bool	unset(t_list *l, char *unset_name)
{
	int		i;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	i = 0;
	while (unset_name[i])
	{
		if (unset_name[i++] == '=')
		{
			ft_putstr_fd("unset: ", STDERR_FILENO);
			ft_putstr_fd(unset_name, STDERR_FILENO);
			ft_putstr_fd(": invalid parameter name", STDERR_FILENO);
			return (FALSE);
		}
	}
	while (l)
	{
		if (!ft_strncmp(unset_name, l->content, ft_strlen(unset_name)))
		{
			next = l->next;
			ft_lstdelone(l, del);
			prev->next = l ->next;
		}
		prev = l;
		l = l->next;
	}
}