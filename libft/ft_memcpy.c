/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:25:25 by gyim              #+#    #+#             */
/*   Updated: 2022/12/03 15:19:17 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;

	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	while (n--)
	{
		*(dest++) = *((char *)src++);
	}
	return (dst);
}
