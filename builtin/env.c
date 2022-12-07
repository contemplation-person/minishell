/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:28:24 by juha              #+#    #+#             */
/*   Updated: 2022/12/07 19:41:03 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_bool	env(t_list *list)
{
	while (list)
	{
		ft_putstr_fd(list->content, STDOUT_FILENO);
		list = list->next;
	}
	return (TRUE);
}
