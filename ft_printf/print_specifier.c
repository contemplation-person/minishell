/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:29:57 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 11:58:22 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_node	*init_node(void)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	if (!ret)
		return (NULL);
	ret->base_show = 0;
	ret->left = 0;
	ret->sign = 0;
	ret->zero = ' ';
	ret->width = -1;
	ret->precision = -1;
	ret->signed_num = 0;
	ret->minus = 0;
	ret->hex_x = '\0';
	return (ret);
}

int	print_specifier(va_list ap, const char *format, int *index)
{
	t_node	*node;
	int		len;

	*index = *index + 1;
	node = init_node();
	if (!node)
		return (0);
	get_options(node, format, index);
	if (option_fail(*node) == 1)
	{
		free(node);
		return (-1);
	}
	len = print_var(ap, *node, format, index);
	free(node);
	return (len);
}
