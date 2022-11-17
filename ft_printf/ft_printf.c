/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:13:05 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:17:05 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		index;
	int		len;
	int		total_len;

	va_start(ap, format);
	index = 0;
	len = 0;
	total_len = 0;
	while (format[index])
	{
		len = print_format(format, &index, ap);
		if (len == -1)
			return (-1);
		total_len += len;
	}
	va_end(ap);
	return (total_len);
}
