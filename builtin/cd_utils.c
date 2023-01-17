/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:59:56 by juha              #+#    #+#             */
/*   Updated: 2023/01/17 15:04:05 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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

int	is_unchanged_dir(t_env_info_list *envp, char **old_pwd, char *new_pwd)
{
	t_env_info	*env;
	int			ret;

	ret = 0;
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
	ret = chdir(new_pwd);
	if (env)
	{
		if (env->value)
			free(env->value);
		env->value = getcwd(NULL, 1);
	}
	return (ret);
}
