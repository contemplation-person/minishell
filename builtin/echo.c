/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:20:36 by juha              #+#    #+#             */
/*   Updated: 2022/11/23 08:20:36 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	char	*option;
	int		option_flag;

	if (argc < 2 || argc > 3)
		return (1);
	option_flag = 0;
	option = argv[1];
	if (ft_strlen(option) == 2 && !ft_strncmp("-n", option, 2))
		option_flag = 1;
	if (option_flag == 1)
		ft_putstr_fd(argv[2], STDOUT_FILENO);
	else
	{
		ft_putstr_fd(argv[1], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	return (0);
}
