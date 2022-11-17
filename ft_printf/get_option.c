/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:58:49 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 09:23:51 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_options(t_node *node, const char *format, int *index)
{
	get_flags(node, format, index);
	get_width(node, format, index);
	if (node->width == -2)
		return ;
	get_precision(node, format, index);
}

void	get_flags(t_node *node, const char *format, int *index)
{
	while (ft_strchr("-+ #0", format[*index]))
	{
		if (format[*index] == '-')
			node->left = 1;
		else if (format[*index] == '+')
			node->sign = 1;
		else if (format[*index] == ' ' && node->sign != 1)
			node->sign = 2;
		else if (format[*index] == '#')
			node->base_show = 1;
		else if (format[*index] == '0')
			node->zero = '0';
		*index = *index + 1;
	}
}

void	get_width(t_node *node, const char *format, int *index)
{
	long long	ret;

	if (!ft_isdigit(format[*index]))
	{
		node->width = -1;
		return ;
	}
	ret = 0;
	while (ft_isdigit(format[*index]))
	{
		ret *= 10;
		ret += format[*index] - '0';
		if (ret >= (long long)2147483647)
		{
			node->width = -2;
			return ;
		}
		*index = *index + 1;
	}
	node->width = ret;
}

void	get_precision(t_node *node, const char *format, int *index)
{
	long long	ret;

	if (format[*index] != '.')
	{
		node->precision = -1;
		return ;
	}
	*index = *index + 1;
	ret = 0;
	while (ft_isdigit(format[*index]))
	{
		ret *= 10;
		ret += format[*index] - '0';
		if (ret >= (long long)2147483646)
		{
			node->precision = -2;
			return ;
		}
		*index = *index + 1;
	}
	node->precision = ret;
}
