/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:28:24 by juha              #+#    #+#             */
/*   Updated: 2022/12/19 11:23:39 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_bool	env(t_env_info_list *minishell_envp, char *str)
{
	if (ft_strncmp(str, "env", ft_strlen(str)))
	{
		ft_putstr_fd("42가 구현하지말래요.\n", STDERR_FILENO);
		return (127);
	}
	else
		print_envp(*minishell_envp, ENV);
	return (0);
}
