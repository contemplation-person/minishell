/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:41:07 by juha              #+#    #+#             */
/*   Updated: 2022/12/10 14:13:24 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	unset_len(char *unset_target)
{
	int	i;

	i = 0;
	while (*unset_target)
	{
		i++;
		if (unset_target == '=')
			break ;
		unset_target++;
	}
	return (i);
}

t_bool	builtin_unset(t_env_info *l, char *unset_name)
{
	int		i;
	int		exist;

	i = 0;
	exist = FALSE;
	while (unset_name[i])
	{
		if (unset_name[i++] == '=')
			exist = TRUE;
	}
	if (exist == FALSE)
	{
		while (l)
		{
			if ((!ft_strncmp(unset_name, l->env, ft_strlen(unset_name))) \
				&& (ft_strlen(unset_name) == unset_len(l->env)))
				remove_env_list(&l);
			l->next;
		}
	}
	return (0);
}
