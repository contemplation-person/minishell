/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:28:24 by juha              #+#    #+#             */
/*   Updated: 2022/12/09 17:45:58 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_bool	env(t_list *list, int argc)
{
	if (argc != 1)
		return (127);
	while (list)
	{
		ft_putstr_fd(list->content, STDOUT_FILENO);
		list = list->next;
	}
	return (0);
}
