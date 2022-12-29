/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:20:36 by juha              #+#    #+#             */
/*   Updated: 2022/11/23 08:20:36 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

enum e_bool
{
	FALSE,
	TRUE,
};

int	main(int argc, char **argv)
{
	char	*str;

	str = NULL;
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("pwd : too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	str = getcwd(str, 1);
	ft_putstr_fd(str, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
