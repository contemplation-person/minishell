/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:26:48 by gyim              #+#    #+#             */
/*   Updated: 2023/01/03 09:25:54 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tnode	*find_op(t_tnode *head)
{
	t_tnode	*target;

	target = check_double_op(head);
	if (target)
		return (target);
	target = check_pipe_op(head);
	if (target)
		return (target);
	// target = check_redirect(head);
	return (target);
}
