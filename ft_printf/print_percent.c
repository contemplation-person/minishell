/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:27:52 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:26:34 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_node node)
{
	int		width;
	char	*str;
	char	*field;

	str = char_to_string('%');
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
