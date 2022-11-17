/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:17:23 by gyim              #+#    #+#             */
/*   Updated: 2022/08/07 14:50:35 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_len(long long n, int base, t_node node)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (node.precision == 0)
			len = 0;
		else
			len = 1;
	}
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		len++;
		n /= base;
	}
	len += node.minus;
	if (node.precision != -1 && node.precision + node.minus > len)
		len = node.precision + node.minus;
	if (node.minus == 0 && node.sign > 0)
		len++;
	return (len);
}

int	unsigned_base_len(unsigned long long n, int base, t_node node)
{
	int					len;
	unsigned long long	num;

	num = n;
	len = 0;
	if (n == 0)
	{
		if (node.precision == 0)
			return (0);
		len = 1;
	}
	while (n > 0)
	{
		len++;
		n /= base;
	}
	if (node.precision != -1 && node.precision > len)
		len = node.precision;
	if ((node.base_show == 1 && num != 0) || node.base_show == 2)
		len += 2;
	return (len);
}
