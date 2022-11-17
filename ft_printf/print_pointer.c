/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:27:35 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:26:18 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list ap, t_node node)
{
	void	*p;
	int		width;
	char	*str;
	char	*field;

	node.hex_x = 'x';
	p = va_arg(ap, void *);
	node.base_show = 2;
	str = uitoa_base((unsigned long long) p, 16, node);
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
