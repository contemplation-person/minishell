/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:21:23 by juha              #+#    #+#             */
/*   Updated: 2023/01/14 17:40:58 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_bool	is_invalid_arg(char *str)
{
	return (ft_isdigit(*str) || *str == '=');
}

t_bool	is_equal_sign(char *excute_str_form)
{
	while (*excute_str_form)
	{
		if (*excute_str_form == '=')
			return (TRUE);
		excute_str_form++;
	}
	return (FALSE);
}

t_bool	builtin_export(t_env_info_list *minishell_envp, char **excute_str_form)
{
	int		size;

	size = 1;
	g_error_code = 0;
	while ((excute_str_form[size]))
	{
		if (is_invalid_arg(excute_str_form[size]))
			builtin_error_message("export", excute_str_form[size], \
									"not a valid identifier", 1);
		else
		{
			if (is_equal_sign(excute_str_form[size]))
				add_env_list(minishell_envp, excute_str_form[size], ENV);
			else
				add_env_list(minishell_envp, excute_str_form[size], EXPORT);
		}
		size++;
	}
	if (size == 1)
		print_envp(*minishell_envp, EXPORT);
	return (TRUE);
}
