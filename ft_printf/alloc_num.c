/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:29:46 by gyim              #+#    #+#             */
/*   Updated: 2022/08/07 16:42:23 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	alloc_num(char *dst, long long n, int len, int base)
{
	const char	hex[] = "0123456789abcdef";
	int			sign;

	sign = 0;
	if (len < 0)
		return ;
	if (n == 0)
		dst[len--] = '0';
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (len >= 0)
	{
		dst[len--] = hex[n % base];
		n /= base;
	}
	if (sign == 1)
		dst[0] = '-';
}

void	alloc_unsigned_num(char *dst, unsigned long long n, int len, int base)
{
	const char	hex[] = "0123456789abcdef";

	if (len < 0)
		return ;
	if (n == 0)
		dst[len--] = '0';
	while (len >= 0)
	{
		dst[len--] = hex[n % base];
		n /= base;
	}
}

char	*alloc_null(char *dst, int *isnull)
{
	char		*ret;
	const char	*str = "(null)";

	if (dst && ft_strlen(dst) >= (size_t)2147483647)
		return (NULL);
	if (dst != NULL)
	{
		*isnull = 0;
		return (dst);
	}
	*isnull = 1;
	ret = malloc(sizeof(char) * 7);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, 7);
	return (ret);
}
