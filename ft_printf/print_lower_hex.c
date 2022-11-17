/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lower_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:58:30 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:27:39 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lower_hex(va_list ap, t_node node)
{
	unsigned int	hex;
	int				width;
	char			*str;
	char			*field;

	node.hex_x = 'x';
	hex = va_arg(ap, unsigned long long);
	str = uitoa_base((unsigned long long) hex, 16, node);
	if (!str)
		return (-1);
	width = find_width(ft_strlen(str), node);
	field = alloc_field(width, node);
	if (!field)
		return (free_str(&str));
	if (write_str(field, str, node) < 0)
		width = -1;
	free_str_field(&field, &str);
	return (width);
}
