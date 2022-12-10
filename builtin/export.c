/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:21:23 by juha              #+#    #+#             */
/*   Updated: 2022/12/10 17:31:56 by juha             ###   ########seoul.kr  */
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

static t_bool	is_valid_export_arg(char *env)
{
	int	i;

	i = -1;
	/*고쳐!*/
	while (env[++i])
	{
		if (env[i] != ft_isalnum(env[i]) && env[i] != '=')
			return (FALSE);
	}
	return (TRUE);
}

static t_bool	print_export(t_env_info *envp_list)
{
	char	*env;
	int		check;

	check = 0;
	env = NULL;
	while (envp_list)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		env = envp_list->env;
		while (*env)
		{
			ft_putchar_fd(*env, STDOUT_FILENO);
			if (*env == '=' && check == 0)
			{
				ft_putchar_fd('\"', STDOUT_FILENO);
				check = 1;
			}
			env++;
		}
		ft_putstr_fd("\"\n", STDOUT_FILENO);
		envp_list = envp_list->next;
	}
	return (0);
}

t_bool	error_export_arg(char *env)
{
	/*while whitespace가 나오는지, 오류 문자인지.*/
	int	i;
	char prev_space;

	i = 0;
	prev_space = *env;
	while (env[i])
	{
		if (!ft_strncmp(&(env[i]), "=", 1) && \
			((8 < prev_space && prev_space < 14) || prev_space == 32))
		{
			return (TRUE);
		}
		else if (!ft_isalnum(env[i]))
			return (TRUE);
		else if (!ft_strncmp(&(env[i]), "=", 1))
			break ;
		prev_space = env[i];
		i++;
	}
	return (FALSE);
}

/*아 내일짜,,,,,,,,,*/
t_bool	builtin_export(t_env_info *minishell_envp, int argc, char *export_env)
{
	int	i;

	if (argc == 1)
		return (print_export(minishell_envp));
	i = 1;
	while (i++ < argc)
	{
		if (!ft_isalpha(*export_env) || error_export_arg(export_env))
		{
			ft_putstr_fd("export: \'", STDOUT_FILENO);
			ft_putstr_fd(export_env, STDOUT_FILENO);
			ft_putstr_fd("\': not a valid identifier\n", STDOUT_FILENO);
			return (1);
		}
		if (is_valid_export_arg(env))
		{
			print_export(minishell_envp);
		}
	}
	return (TRUE);
}
