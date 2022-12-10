/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:41:07 by juha              #+#    #+#             */
/*   Updated: 2022/12/09 17:50:16 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	free_str(void *str)
{
	free(str);
}

static void	del_target_list(t_list *l, char *unset_name)
{
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	while (l)
	{
		if (!ft_strncmp(unset_name, l->content, ft_strlen(unset_name)))
		{
			next = l->next;
			ft_lstdelone(l, free_str);
			if (next == NULL)
				return ;
			prev->next = next;
			return ;
		}
		prev = l;
	}
}

t_bool	unset(t_list *l, char *unset_name)
{
	int		i;

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
	del_target_list(l, unset_name);
	return (TRUE);
}
