/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:21:23 by juha              #+#    #+#             */
/*   Updated: 2022/12/31 17:53:56 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
/*
	- first char is number
	bash-5.2$ export 0test
	bash: export: `0test': not a valid identifier
	- whitespace after equire
	bash-5.2$ export test =
	bash: export: `=': not a valid identifier
	
	- valid char ;
	bash-5.2$ export test/
	bash: export: `test/': not a valid identifier
	bash-5.2$ export test!=
	bash: export: `test!=': not a valid identifier
	
	갯수가 여러개면 여러번 출력.
	ex) test1=test test2=test test -> export ->>> test1,  test2 // no space
	같은 값이면, 덮어씀.
	띄어어쓰기 문제.
	test0=test 정상  
	test=====  정상 출력
	test       정상 출력 (저장  안함.)
*/

static t_bool	is_valid_arg(char *str)
{
	if (ft_isdigit(*str) || *str == '=')
		return (FALSE);
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '=')
			return (FALSE);
		str++;
	}
	return (TRUE);
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
	t_bool	print_flag;

	size = 1;
	g_error_code = 0;
	while ((excute_str_form[size]))
	{
		print_flag = is_valid_arg(excute_str_form[size]);
		if (!print_flag)
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
