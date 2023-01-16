/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:38:03 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 15:43:26 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_list.h"

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
