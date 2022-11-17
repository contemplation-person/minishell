/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:11:21 by gyim              #+#    #+#             */
/*   Updated: 2022/08/07 14:46:25 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_base(long long n, int base, t_node node)
{
	int		num_len;
	char	*ret;

	num_len = base_len(n, base, node);
	ret = malloc(sizeof(char) * (num_len + 1));
	if (!ret)
		return (NULL);
	ret[num_len--] = '\0';
	alloc_num(ret, n, num_len, 10);
	add_sign(ret, node, num_len);
	return (ret);
}

char	*uitoa_base(unsigned long long n, int base, t_node node)
{
	int			num_len;
	char		*ret;

	num_len = unsigned_base_len(n, base, node);
	ret = malloc(sizeof(char) * (num_len + 1));
	if (!ret)
		return (NULL);
	ret[num_len--] = '\0';
	alloc_unsigned_num(ret, n, num_len, base);
	if ((node.base_show == 1 && n != 0) || node.base_show == 2)
	{
		ret[0] = '0';
		ret[1] = node.hex_x;
	}
	return (ret);
}

char	*char_to_string(char ch)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	ret[1] = '\0';
	ret[0] = ch;
	return (ret);
}
