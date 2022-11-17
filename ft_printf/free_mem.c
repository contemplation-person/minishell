/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 11:28:45 by gyim              #+#    #+#             */
/*   Updated: 2022/08/07 13:27:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	free_str(char **str)
{
	free(*str);
	*str = NULL;
	return (-1);
}

void	free_str_field(char **str, char **field)
{
	free(*str);
	free(*field);
	*str = NULL;
	*field = NULL;
}

int	free_null(char **str, int isnull)
{
	if (isnull == 1)
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	return (-1);
}
