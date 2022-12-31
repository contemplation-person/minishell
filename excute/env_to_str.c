/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:25:01 by gyim              #+#    #+#             */
/*   Updated: 2022/12/31 21:26:11 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

char	*envp_node_to_str(t_env_info *node)
{
	int		len;
	char	*key_value;

	len = ft_strlen(node->key) + ft_strlen(node->value) + 1;
	key_value = ft_calloc(len + 1, sizeof(char));
	if (!key_value)
		return (NULL);
	ft_strlcat(key_value, node->key, len + 1);
	ft_strlcat(key_value, "=", len + 1);
	ft_strlcat(key_value, node->value, len + 1);
	return (key_value);
}

char	**envp_list_to_arr(t_env_info_list *envp_list)
{
	char		**envp_arr;
	t_env_info	*curr;
	int			i;

	envp_arr = ft_calloc(envp_list->cnt + 1, sizeof(char *));
	if (!envp_arr)
		return (NULL);
	i = 0;
	curr = envp_list->env_info;
	while (curr)
	{
		envp_arr[i] = envp_node_to_str(curr);
		i++;
		curr = curr->next;
	}
	return (envp_arr);
}