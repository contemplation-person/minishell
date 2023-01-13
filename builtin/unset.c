/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:41:07 by juha              #+#    #+#             */
/*   Updated: 2023/01/13 18:46:56 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin/builtin.h"

t_bool	builtin_unset(t_env_info_list *l, char **excute_str_form)
{
	t_env_info	*node;

	if (!l)
		return (FALSE);
	excute_str_form++;
	while (*excute_str_form)
	{
		node = l->env_info;
		while (node)
		{
			if (!ft_strncmp(node->key, *excute_str_form, \
				ft_strlen(*excute_str_form) + 1))
			{
				delete_one_list(l, *excute_str_form);
			}
			node = node->next;
		}
		excute_str_form++;
	}
	g_error_code = 0;
	return (TRUE);
}
