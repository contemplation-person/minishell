/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:23:43 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:17:19 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_upper_all(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

char	*get_str(char *temp, t_node node)
{
	int		temp_len;
	int		ret_len;
	char	*ret;

	temp_len = ft_strlen(temp);
	if (node.precision == -1)
		ret_len = temp_len;
	else
	{
		if (node.precision > temp_len)
			ret_len = temp_len;
		else
			ret_len = node.precision;
	}
	ret = malloc(sizeof(char) * (ret_len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, temp, ret_len + 1);
	return (ret);
}

void	add_sign(char *dst, t_node node, int len)
{
	if (len < 0)
		return ;
	if (node.sign == 1)
	{
		if (node.minus == 1)
			dst[0] = '-';
		else
			dst[0] = '+';
	}
	else if (node.sign == 2)
	{
		if (node.minus == 1)
			dst[0] = '-';
		else
			dst[0] = ' ';
	}
}

int	option_fail(t_node node)
{
	if (node.width == -2 || node.precision == -2)
		return (1);
	else
		return (0);
}

int	print_format(const char *format, int *index, va_list ap)
{
	int	len;

	if (format[*index] == '%')
	{
		len = print_specifier(ap, format, index);
		if (len == -1)
			return (-1);
		return (len);
	}
	else
	{
		if (write(1, &format[(*index)++], 1) < 0)
			return (-1);
		return (1);
	}
}
