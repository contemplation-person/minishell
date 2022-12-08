/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:21:23 by juha              #+#    #+#             */
/*   Updated: 2022/12/08 17:31:55 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
/*
	test ===이이면  문제  있음
	bash: export: `===': not a valid identifier
	export test/
	bash: export: `test/': not a valid identifier
	/t 슬러시는 사라짐
	0test= 비정상.


	같은 값이면, 덮어씀.
	띄어어쓰기 문제.
	test0=test 정상  
	test=====  정상 출력
	test       정상 출력 (저장  안함.)

*/

static t_bool	is_valid_export_arg(char *env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (env[i] != ft_isalnum(env[i]) && env[i] != '=')
			return (FALSE);
	}
	return (TRUE);
}

static t_bool	print_export(t_list *envp_list)
{
	while (envp_list)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(envp_list->content, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		envp_list = envp_list->next;
	}
	return (0);
}

t_bool	builtin_export(t_list **minishell_envp, int argc, char *env)
{
	if (argc == 1)
		return (print_export(*minishell_envp));
	if (!ft_isdigit(*env))
	{
		return (1);
	}
	if (is_valid_export_arg(env))
	{
		ft_lstadd_back(minishell_envp, ft_lstnew(ft_strdup(env)));
	}
	return (TRUE);
}
