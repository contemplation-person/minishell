/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:23 by juha              #+#    #+#             */
/*   Updated: 2023/01/05 08:22:10 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_list.h"

static int	cnt_key_i(char *env)
{
	int	key_i;

	key_i = 0;
	while (env[key_i])
	{
		if (env[key_i] == '=')
			break ;
		key_i++;
	}
	return (key_i);
}

static void	_set_value(int value_i, int key_i, t_env_info *ret, char *env)
{
	if (value_i == key_i)
		ret->value = NULL;
	else
	{
		ret->value = ft_substr(env, key_i + 1, value_i);
		if (!ret->value)
			exit(errno);
	}
}

t_env_info	*new_env_list(char *env)
{
	t_env_info	*ret;
	int			key_i;
	int			value_i;

	ret = ft_calloc(1, sizeof(t_env_info));
	if (!ret)
		exit(errno);
	key_i = cnt_key_i(env);
	ret->key = ft_substr(env, 0, key_i);
	if (!ret->key)
		exit(errno);
	value_i = key_i;
	while (env[value_i++])
		;
	_set_value(value_i, key_i, ret, env);
	ret->feature = EXPORT;
	if (!ret->value)
		ret->feature = ENV;
	return (ret);
}

void	env_node_free(t_env_info **node)
{
	if ((*node)->value)
	{
		free((*node)->value);
		(*node)->value = NULL;
	}
	free((*node)->key);
	(*node)->key = NULL;
	free(*node);
	*node = NULL;
}

static void	free_node(t_env_info_list *list, t_env_info *node, int *idx)
{
	list->cnt--;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	*idx = node->index;
	env_node_free(&node);
	node = list->env_info;
	while (node)
	{
		if (*idx < node->index)
			node->index--;
		node = node->next;
	}
}

void	delete_one_list(t_env_info_list *list, char *key)
{
	t_env_info	*node;
	int			idx;

	node = list->env_info;
	if (list->cnt == 0)
		return ;
	if (list->cnt == 1)
		env_node_free(&(list->env_info));
	if (node->key == key)
	{
		list->env_info = node->next;
		env_node_free(&(list->env_info));
		return ;
	}
	while (node)
	{
		if (!ft_strncmp(key, node->key, ft_strlen(key) + 1))
			return (free_node(list, node, &idx));
		node = node->next;
	}
}
