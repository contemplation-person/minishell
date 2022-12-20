/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:23 by juha              #+#    #+#             */
/*   Updated: 2022/12/20 15:34:00 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_list.h"

t_env_info	*new_env_list(char *env)
{
	t_env_info	*ret;
	int			key_i;
	int			value_i;

	ret = ft_calloc(sizeof(t_env_info), 1);
	if (!ret)
		exit(errno);
	key_i = 0;
	while (env[key_i])
	{
		if (env[key_i] == '=')
			break ;
		key_i++;
	}
	ret->key = ft_substr(env, 0, key_i);
	value_i = key_i;
	while (env[value_i++])
		;
	if (value_i == key_i)
		ret->value = NULL;
	else
		ret->value = ft_substr(env, key_i + 1, value_i);
	ret->feature = EXPORT;
	if (!ret->value)
		ret->feature = ENV;
	return (ret);
}

static t_bool	find_same_key(t_env_info **node, t_env_info **new_node)
{
	t_env_info	*temp_node;
	t_env_info	*temp_new_node;

	temp_node = *node;
	temp_new_node = *new_node;
	while (temp_node)
	{
		if (!ft_strncmp(temp_node->key, temp_new_node->key, \
			ft_strlen(temp_node->key)))
		{
			free(temp_new_node->key);
			if (temp_node->value)
				free(temp_node->value);
			temp_node->value = temp_new_node->value;
			if (temp_node->value)
				temp_node->feature = ENV;
			free(temp_new_node);
			temp_new_node = NULL;
			return (TRUE);
		}
		temp_node = temp_node->next;
	}
	return (FALSE);
}

void	add_env_list(t_env_info_list *list,\
					char *env, t_env_feature feature)
{
	t_env_info	*temp;
	t_env_info	*n_temp;

	temp = list->env_info;
	n_temp = new_env_list(env);
	n_temp->feature = feature;
	if (find_same_key(&temp, &n_temp))
		return ;
	list->cnt++;
	while (temp && temp->next)
	{
		if (0 > ft_strncmp(temp->key, n_temp->key, ft_strlen(temp->key)))
			(n_temp->index)++;
		else if (0 < ft_strncmp(temp->key, n_temp->key, ft_strlen(temp->key)))
			(temp->index)++;
		temp = temp->next;
	}
	if (list->cnt == 1)
		list->env_info = n_temp;
	else
	{
		temp->next = n_temp;
		n_temp->prev = temp;
	}
}

void	print_envp(t_env_info_list minishell_envp, t_env_feature feature)
{
	t_env_info		*temp;

	temp = minishell_envp.env_info;
	if (feature == EXPORT)
	{
		while (temp)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(temp->key, STDOUT_FILENO);
			if (temp->value)
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(temp->value, STDOUT_FILENO);
				ft_putstr_fd("\"",STDOUT_FILENO);
			}
			ft_putchar_fd('\n', STDOUT_FILENO);
			temp = temp->next;
		}
	}
	else
	{
		while (temp)
		{
			if (temp->feature == ENV)
			{
				ft_putstr_fd(temp->key, STDOUT_FILENO);
				ft_putstr_fd("=", STDOUT_FILENO);
				ft_putstr_fd(temp->value, STDOUT_FILENO);
				ft_putchar_fd('\n', STDOUT_FILENO);
			}
			temp = temp->next;
		}
	}
}

void	delete_one_list(t_env_info_list *list, char *key)
{
	t_env_info	*node;
	int			idx;

	node = list->env_info;
	if (list->cnt == 0)
		return ;
	while (node)
	{
		if (!ft_strncmp(key, node->key, ft_strlen(key) - 1))
		{
			list->cnt--;
			if (node->prev && node->next)
			{
				node->prev->next = node->next;
				node->next->prev = node->prev;
			}
			else if (node->prev)
				node->prev->next = node->next;
			else if (node->next)
				list->env_info = node->next;
			idx = node->index;
			free(node->value);
			free(node->key);
			free(node);
			node = list->env_info;
			while (node)
			{
				if (idx < node->index)
					node->index--;
				node = node->next;
			}
			return ;
		}
		node = node->next;
	}
}
