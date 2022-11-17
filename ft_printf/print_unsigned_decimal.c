/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:43:21 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:27:06 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_decimal(va_list ap, t_node node)
{
	unsigned int	decimal;
	int				width;
	char			*str;
	char			*field;

	decimal = va_arg(ap, unsigned int);
	str = uitoa_base((unsigned long long) decimal, 10, node);
	if (!str)
		return (-1);
	width = find_width(ft_strlen(str), node);
	field = alloc_field(width, node);
	if (!field)
		return (free_str(&str));
	if (write_str(field, str, node) < 0)
		width = -1;
	free_str_field(&str, &field);
	return (width);
}
