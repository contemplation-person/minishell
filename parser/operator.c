/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:20:19 by gyim              #+#    #+#             */
/*   Updated: 2022/11/26 17:14:26 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	op_check(char *token)
{
	if (ft_strncmp(token, "$$", 3) == 0)
		return (D_AMP);
	else if (ft_strncmp(token, "||", 3) == 0)
		return (D_PIPE);
	return (0);
}

int	op_index(char **token)
{
	t_linked_stack	*p_stack;
	int				i;
	int				pair;
	int				ret;

	p_stack = create_linked_stack();
	ret = -1;
	i = 0;
	while (token[i])
	{
		if (p_stack->cnt == 0 && op_check(token[i]) == 0)
		{
			ret = i++;
			continue ;
		}
		if (is_a_pair_stack(&p_stack, token[i][0]))
		{
			i++;
			continue ;
		}
		pair = p_start_check(token[i]);
		if (pair > 0)
			input_a_pair_stack(&p_stack, token[i][0]);
		i++;
	}
	if (p_stack->cnt != 0)
	{
		write(2, "quote not end\n", 14);
		return (-2);
	}
	delete_stack(p_stack);
	return (ret);
}