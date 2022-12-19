/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:41:07 by juha              #+#    #+#             */
/*   Updated: 2022/12/19 20:28:38 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin/builtin.h"

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

t_bool	builtin_unset(t_env_info_list *l, char **excute_str_form)
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
			if ((!ft_strncmp(unset_name, l->key, ft_strlen(l->key))) \
				&& (ft_strlen(unset_name) == ft_strlen(l->key)))
				remove_env_list(&l);
			l->next;
		}
	}
	return (0);
}
