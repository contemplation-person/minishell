/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:56:29 by gyim              #+#    #+#             */
/*   Updated: 2023/01/17 16:21:30 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	op_valid_check(t_tnode *prev, t_tnode *curr)
{
	if (curr == NULL)
	{
		if (is_redirection(prev->token) || is_pipe(prev->token)
			|| is_double_op(prev->token))
			return (-1);
	}	
	if (is_redirection(prev->token) && !is_word(curr->token))
		return (-1);
	if (is_pipe(prev->token) && is_double_op(curr->token))
		return (-1);
	if (is_double_op(prev->token) && is_double_op(curr->token))
		return (-1);
	return (0);
}
