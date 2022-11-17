/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:12:40 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:18:27 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*alloc_field(int len, t_node node)
{
	char	*ret;
	int		i;
	char	c;

	if (node.precision != -1 || node.left == 1)
		c = ' ';
	else
		c = node.zero;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = c;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	find_width(int slen, t_node node)
{
	int	print_len;

	if (node.width == -1)
		print_len = slen;
	else if (node.width > slen)
		print_len = node.width;
	else
		print_len = slen;
	return (print_len);
}

int	write_str(char *dst, char *src, t_node node)
{
	int		srclen;
	int		dstlen;
	int		start;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (node.left == 1)
		start = 0;
	else
		start = dstlen - srclen;
	ft_memcpy(dst + start, src, srclen);
	move_sign(dst, start, node);
	if (write(1, dst, dstlen) < 0)
		return (-1);
	return (0);
}

void	move_sign(char *dst, int start, t_node node)
{
	if (node.zero == '0' && (node.minus == 1 || node.sign > 0))
	{
		if (node.precision == -1 && start != 0)
		{
			*(dst) = *(dst + start);
			*(dst + start) = '0';
		}
	}
	if (node.zero == '0' && dst[start] == '0'
		&& (dst[start + 1] == 'x' || dst[start + 1] == 'X'))
	{
		if (node.precision == -1 && start != 0)
		{
			*(dst) = *(dst + start);
			*(dst + start) = '0';
			*(dst + 1) = *(dst + start + 1);
			*(dst + start + 1) = '0';
		}
	}
}

void	invalid_parameter(char c, int *index)
{
	if (!ft_isalpha(c))
		*index = *index - 1;
}
