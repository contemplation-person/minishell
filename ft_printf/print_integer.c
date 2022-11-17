/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:40:55 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:27:57 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list ap, t_node node)
{
	long long	decimal;
	int			width;
	char		*str;
	char		*field;

	decimal = va_arg(ap, int);
	if (decimal < 0)
		node.minus = 1;
	str = itoa_base(decimal, 10, node);
	if (!str)
		return (-1);
	width = find_width((int)ft_strlen(str), node);
	field = alloc_field(width, node);
	if (!field)
		return (free_str(&str));
	if (write_str(field, str, node) < 0)
		width = -1;
	free_str_field(&str, &field);
	return (width);
}
