/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:23 by juha              #+#    #+#             */
/*   Updated: 2022/12/21 15:20:43 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_list.h"

typedef enum	e_export
{
	EXPORT,
	ENV,
}t_export;

t_env_node	*new_env_node(char *key, char *value)
{
	t_env_node	*node;

	if (!(*key))
		return (NULL);
	node = ft_calloc(sizeof(t_env_node), 1);
	if (!node)
		return (NULL);
	node->key = key;
	if (*value)
		node->value = value;
	else
		node->value = NULL;
	return (node);
}

void	env_del(t_env_node *target)
{
	if (target->key)
		free(target->key);
	if (target->value)
		free(target->value);
	free(target);
	target = NULL;
}

void	print_env(t_list *list, t_export flag)
{
	t_list	*iter;

	iter = list;
	if (flag == EXPORT)
	{
		while (iter)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(((t_env_node *)iter->content)->key, STDOUT_FILENO);
			if (((t_env_node *)iter->content)->value)
			{
				ft_putchar_fd("=", STDOUT_FILENO);
				ft_putendl_fd(((t_env_node *)iter->content)->value, STDOUT_FILENO);
			}
			else
				ft_putchar_fd('\n', STDOUT_FILENO);
			iter = iter->next;
		}
	}
	else
	{
		while (iter)
		{
			if (((t_env_node *)iter->content)->value)
			{
				ft_putstr_fd(((t_env_node *)iter->content)->key, STDOUT_FILENO);
				ft_putchar_fd("=", STDOUT_FILENO);
				ft_putendl_fd(((t_env_node *)iter->content)->value, STDOUT_FILENO);
			}
			iter = iter->next;
		}
	}
}