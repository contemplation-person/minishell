/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:59 by gyim              #+#    #+#             */
/*   Updated: 2023/01/17 15:03:45 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*set_pwd(char *excute_str_form, char *home)
{
	char	*ret;
	char	*temp;

	ret = NULL;
	if (excute_str_form[0] == '~')
	{
		ret = ft_strjoin(home, "/");
		temp = ret;
		ret = ft_strjoin(temp, excute_str_form + 2);
		if (!temp || !ret)
			exit(1);
		free(temp);
	}
	return (ret);
}

t_bool	check_cd_error(t_env_info_list *minishell_envp, char **excute_str_form)
{
	if (cnt_argc(excute_str_form) > 2)
	{
		builtin_error_message("MINISHELL : ", "cd", "too many arguments", 1);
		return (TRUE);
	}
	else if (cnt_argc(excute_str_form) == 1)
	{
		if (!find_env(minishell_envp, "HOME"))
		{
			builtin_error_message("MINISHELL : ", "cd", "home not set", 1);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	update_env_pwd(char **excute_str_form, char **old_pwd, char **new_pwd)
{
	*old_pwd = getcwd(NULL, 1);
	if (!(*old_pwd))
	{
		chdir(getenv("HOME"));
		return (FALSE);
	}
	if (cnt_argc(excute_str_form) == 1)
	{
		*new_pwd = getenv("HOME");
		if (!(*new_pwd))
			exit(1);
	}
	else
		*new_pwd = excute_str_form[1];
	return (TRUE);
}

t_bool	builtin_cd(t_env_info_list *minishell_envp, char **excute_str_form)
{
	char	*old_pwd;
	char	*new_pwd;

	g_error_code = 0;
	if (check_cd_error(minishell_envp, excute_str_form))
		return (FALSE);
	if (!update_env_pwd(excute_str_form, &old_pwd, &new_pwd))
		return (FALSE);
	if (cnt_argc(excute_str_form) > 1 && excute_str_form[1] \
				&& excute_str_form[1][0] == '~')
		new_pwd = set_pwd(excute_str_form[1], getenv("HOME"));
	if (is_unchanged_dir(minishell_envp, &old_pwd, new_pwd))
		builtin_error_message("MINISHELL ", excute_str_form[1], \
								"No such file or directory", 1);
	if (cnt_argc(excute_str_form) > 1 && excute_str_form[1] \
				&& excute_str_form[1][0] == '~')
		free(new_pwd);
	return (TRUE);
}
