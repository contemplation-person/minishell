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

#include "builtin.h"

int	pwd(char *str)
{
	if (ft_strncmp(str, "pwd", ft_strlen(str)))
	{
		ft_putstr_fd("pwd : too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	str = getcwd(str, 1);
	ft_putstr_fd(str, STDIN_FILENO);
	return (EXIT_SUCCESS);
}
