/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:45 by juha              #+#    #+#             */
/*   Updated: 2022/12/22 17:44:26 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_struct.h"
#include "builtin.h"

void	builtin_error_message(char *name, char *error, \
								char *message, int error_code)
{
	g_error_code = error_code;
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
}
