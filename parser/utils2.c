/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:54:06 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 07:59:31 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_word(char *target)
{
	if (is_redirection(target) || is_pipe(target)
		|| is_double_op(target) || is_parenthesis(target))
		return (FALSE);

	return (TRUE);
}

int	is_pipe(char	*target)
{
	if (ft_strncmp(target, "|", 2) == 0)
		return (TRUE);
	return (FALSE);
}

int	is_double_op(char *target)
{
	if (ft_strncmp(target, "&&", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(target, "||", 3) == 0)
		return (TRUE);
	return (FALSE);
}

int	is_parenthesis(char *target)
{
	if (ft_strncmp(target, "(", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(target, ")", 2) == 0)
		return (TRUE);
	return (FALSE);
}
