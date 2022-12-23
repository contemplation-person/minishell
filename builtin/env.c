/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:28:24 by juha              #+#    #+#             */
/*   Updated: 2022/12/23 15:23:42 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_bool	builtin_env(t_env_info_list *minishell_envp, char **excute_str_form)
{
	int	i;

	i = 0;
	while (excute_str_form[0])
	{
		i++;
	}
	if (i > 1)
	{
		builtin_error_message("42가", "구현하지말래요", "", 127);
		return (1);
	}
	else
		print_envp(*minishell_envp, ENV);
	return (0);
}
