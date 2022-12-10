/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:28:24 by juha              #+#    #+#             */
/*   Updated: 2022/12/10 17:27:05 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_bool	env(t_list *list, int argc)
{
	if (argc != 1)
	{
		ft_putstr_fd("42가 구현하지말래요.\n", STDERR_FILENO);
		return (127);
	}
	while (list)
	{
		ft_putstr_fd(list->content, STDOUT_FILENO);
		list = list->next;
	}
	return (0);
}
