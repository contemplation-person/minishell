/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:58:39 by gyim              #+#    #+#             */
/*   Updated: 2022/08/07 16:51:17 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_var(va_list ap, t_node node, const char *format, int *index)
{
	int	len;

	len = 0;
	if (format[(*index)] == 'c')
		len = print_char(ap, node);
	else if (format[(*index)] == 's')
		len = print_string(ap, node);
	else if (format[(*index)] == 'p')
		len = print_pointer(ap, node);
	else if (format[(*index)] == 'd')
		len = print_decimal(ap, node);
	else if (format[(*index)] == 'i')
		len = print_integer(ap, node);
	else if (format[(*index)] == 'u')
		len = print_unsigned_decimal(ap, node);
	else if (format[(*index)] == 'x')
		len = print_lower_hex(ap, node);
	else if (format[(*index)] == 'X')
		len = print_upper_hex(ap, node);
	else if (format[(*index)] == '%')
		len = print_percent(node);
	else
		invalid_parameter(format[(*index)], index);
	*index = *index + 1;
	return (len);
}
