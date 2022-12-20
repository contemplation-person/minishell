/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:59 by gyim              #+#    #+#             */
/*   Updated: 2022/12/08 19:56:01 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
/* 새로 만들 것.*/
int	cd(int argc, char **argv)
{
	char	*result;
	int		flag;

	if (argc == 1)
	{
		flag = chdir("$HOME");
		result = getcwd(NULL, 1000000);
		ft_printf("chdir flag : %d\n", flag);
		ft_printf("changed :dir : %s\n", result);
		exit(0);
	}
	flag = chdir(argv[1]);
	result = getcwd(NULL, 1000000);
	ft_printf("chdir flag : %d\n", flag);
	ft_printf("changed :dir : %s\n", result);
	return (0);
}
