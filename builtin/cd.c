/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:59 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 16:17:27 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <unistd.h>

t_env_info	*find_env(t_env_info_list *envp, char *key)
{
	t_env_info	*ret;

	ret = envp->env_info;
	while (ret)
	{
		if (!ft_strncmp(ret->key, key, ft_strlen(key) + 1))
			break ;
		ret = ret->next;
	}
	return (ret);
}

static void	change_dir(t_env_info_list *envp, char **old_pwd, char *new_pwd)
{
	t_env_info	*env;

	env = find_env(envp, "OLDPWD");
	if (env)
	{
		if (env->value)
			free(env->value);
		env->value = *old_pwd;
	}
	else
		free(old_pwd);
	env = find_env(envp, "PWD");
	chdir(new_pwd);
	if (env)
	{
		if (env->value)
			free(env->value);
		env->value = getcwd(NULL, 1);
	}
}

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
	char	*find_path;

	if (cnt_argc(excute_str_form) == 0)
		return (FALSE);
	if (cnt_argc(excute_str_form) > 2)
	{
		builtin_error_message("MINISHELL ", "cd", "too many arguments", 1);
		return (TRUE);
	}
	else if (cnt_argc(excute_str_form) == 1)
	{
		if (!find_env(minishell_envp, "HOME"))
		{
			builtin_error_message("MINISHELL ", "cd", "home not set", 1);
			return (TRUE);
		}
	}
	if (excute_str_form[1][0] == '~')
		find_path = ft_strjoin(getenv("HOME"), excute_str_form[1] + 1);
	else
		find_path = ft_strdup(excute_str_form[1]);
	if (access(find_path, F_OK) == -1)
	{
		builtin_error_message("MINISHELL ", \
			"cd", "No such file or directory", 1);
		free(find_path);
		return (TRUE);
	}
	free(find_path);
	return (FALSE);
}///

t_bool	builtin_cd(t_env_info_list *minishell_envp, char **excute_str_form)
{
	char	*old_pwd;
	char	*new_pwd;

	g_error_code = 0;
	if (check_cd_error(minishell_envp, excute_str_form))
		return (FALSE);
	old_pwd = getcwd(NULL, 1);
	if (cnt_argc(excute_str_form) == 1)
	{
		new_pwd = getenv("HOME");
		if (!new_pwd)
			exit(1);
	}
	else
		new_pwd = excute_str_form[1];
	if (cnt_argc(excute_str_form) > 1 && excute_str_form[1] \
				&& excute_str_form[1][0] == '~')
		new_pwd = set_pwd(excute_str_form[1], getenv("HOME"));
	change_dir(minishell_envp, &old_pwd, new_pwd);
	if (cnt_argc(excute_str_form) > 1 && excute_str_form[1] \
			&& excute_str_form[1][0] == '~')
		free(new_pwd);
	return (TRUE);
}
