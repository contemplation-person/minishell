/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:29:45 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:24:58 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list ap, t_node node)
{
	char	*temp;
	int		width;
	char	*field;
	int		isnull;
	char	*str;

	temp = (char *)va_arg(ap, char *);
	temp = alloc_null(temp, &isnull);
	if (temp == NULL)
		return (-1);
	str = get_str(temp, node);
	if (!str)
		return (free_null(&temp, isnull));
	width = find_width(ft_strlen(str), node);
	field = alloc_field(width, node);
	if (!field)
	{
		free_null(&temp, isnull);
		return (free_str(&str));
	}
	if (write_str(field, str, node) < 0)
		width = -1;
	free_null(&temp, isnull);
	free_str_field(&str, &field);
	return (width);
}
