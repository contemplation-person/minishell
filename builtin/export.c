/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:21:23 by juha              #+#    #+#             */
/*   Updated: 2022/12/19 08:21:24 by juha             ###   ########seoul.kr  */
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

	i = 0;
	/*고쳐!*/
	while (env[i])
	{
		if (env[i] != ft_isalnum(env[i]) && env[i] != '=')
			return (FALSE);
		i++;
	}
	return (TRUE);
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

t_bool	builtin_export(t_env_info_list *minishell_envp, char *str)
{
	int	i;

	if (!ft_strncmp(str, "export", ft_strlen("export")) && ft_strlen(str) == 6)
	{
		print_envp(*minishell_envp, EXPORT);
		return (0);
	}
	/*line???? token???*/
	i = 0;
	while (i < minishell_envp->cnt)
	{
		if (!ft_isalpha(str[i++]) || error_export_arg(str))
		{
			ft_putstr_fd("export: \'", STDOUT_FILENO);
			ft_putstr_fd(str, STDOUT_FILENO);
			ft_putstr_fd("\': not a valid identifier\n", STDOUT_FILENO);
			return (1);
		}
		if (is_valid_export_arg(env))
		{
			print_envp(*minishell_envp, ENV);
		}
	}
	return (TRUE);
}
