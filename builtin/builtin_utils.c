/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:45 by juha              #+#    #+#             */
/*   Updated: 2022/12/21 19:50:33 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_struct.h"
#include "builtin.h"

void	builtin_error_message(char *builtin_name, char *error, \
								char *message, int error_code)
{
	g_error_code = error_code;
	ft_putstr_fd(builtin_name, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
}