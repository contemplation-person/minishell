/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:19:25 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:21:10 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap, t_node node)
{
	char	ch;
	int		len;
	char	*str;
	int		start;

	ch = (char)va_arg(ap, int);
	if (node.width != -1 && node.width > 1)
		len = node.width;
	else
		len = 1;
	str = alloc_field(len, node);
	if (!str)
		return (0);
	if (node.left == 0)
		start = len - 1;
	else
		start = 0;
	ft_memcpy(str + start, &ch, 1);
	if (write(1, str, len) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}
