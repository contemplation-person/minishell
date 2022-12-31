/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:41:07 by juha              #+#    #+#             */
/*   Updated: 2022/12/31 12:20:39 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin/builtin.h"

/*
	옵션  없는  unset
	if (key값이 같으면 지움)
		return (0);
	if (key 값이 다르면 지우지 않음)
*/
t_bool	builtin_unset(t_env_info_list *l, char **excute_str_form)
{
	t_env_info	*node;

	if (!l)
		return (FALSE);
	while (*excute_str_form)
	{
		node = l->env_info;
		while (node)
		{
			if (!ft_strncmp(node->key, *excute_str_form, \
				ft_strlen(*excute_str_form) + 1))
				delete_one_list(l, *excute_str_form);
			node = node->next;
		}
		excute_str_form++;
	}
	g_error_code = 0;
	return (TRUE);
}
