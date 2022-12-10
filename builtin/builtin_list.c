/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:23 by juha              #+#    #+#             */
/*   Updated: 2022/12/10 22:49:52 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_env_info	*new_env_list(char *key, char *value, t_env_feature feature)
{
	t_env_info	*ret;

	ret = calloc(sizeof(t_env_info), 1);
	if (!ret)
		exit(errno);
	ret->key = ft_strdup(key);
	ret->value = ft_strdup(value);
	if (!(ret->key) || !(ret->value))
		exit(errno);
	ret->next = NULL;
	ret->prev = NULL;
	ret->feature = feature;
	return (ret);
}

void	remove_env_list(t_env_info **list)
{
	t_env_info	*l;

	l = *list;
	if (l == NULL)
		return ;
	free(l->key);
	l->key = NULL;
	free(l->value);
	l->value = NULL;
	if (l->prev == NULL)
		*list = l->next;
	free(l);
	l = NULL;
}

void	add_back(t_env_info *l, char *export_env)
{
	t_env_info	*temp;
	int			key_i;
	int			value_i;

	temp = l;
	while (temp)
		temp = temp->next;
	key_i = -1;
	while (export_env[++key_i])
	{
		if (export_env[key_i] == '=')
			break ;
		key_i++;
	}
	value_i = key_i;
	while (export_env[++value_i])
		value_i++;
	temp->next = new_env_list(ft_strlcpy())
	return (l);
}

t_env_info	*init_env(char **envp)
{
	if (!(*envp))
		return (NULL);
}

void	print_envp(t_env_info *envp)
{
	while (envp)
	{
		ft_putstr_fd(envp->key, STDIN_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putstr_fd(envp->value, STDOUT_FILENO);
		// printf("data : %s\n feature %s\n", envp->env, (envp->feature?"ENV":"EXPORT"));
		envp = envp->next;
	}
}
