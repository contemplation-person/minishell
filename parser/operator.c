/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:20:19 by gyim              #+#    #+#             */
/*   Updated: 2022/11/28 13:55:14 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	op_check(char *token)
{
	if (ft_strncmp(token, "&&", 3) == 0)
		return (D_AMP);
	else if (ft_strncmp(token, "||", 3) == 0)
		return (D_PIPE);
	else if (ft_strncmp(token, "|", 2) == 0)
		return (PIPE);
	return (0);
}

int	get_op_index(char **token)
{
	t_linked_stack	*p_stack;
	int				i;
	int				pair;
	int				ret;

	ret = -1;
	i = 0;
	while (token[i])
	{
		if (op_check(token[i]) > 0)
			ret = i;
		i++;
	}
	return (ret);
}
