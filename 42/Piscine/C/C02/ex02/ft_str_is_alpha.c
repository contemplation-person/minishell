/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:51:34 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 21:07:42 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(('a' <= str[i] && str[i] <= 'z')
				|| ('A' <= str[i] && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
