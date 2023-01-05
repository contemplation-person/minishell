/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:45 by juha              #+#    #+#             */
/*   Updated: 2023/01/04 16:30:22 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_struct.h"
#include "../minishell.h"
#include "builtin.h"

void	builtin_error_message(char *name, char *error, \
								char *message, int error_code)
{
	g_error_code = error_code;
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": \'", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd("\': ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
}

int	cnt_argc(char **excute_str_form)
{
	int	i;

	i = 0;
	while (excute_str_form[i])
		i++;
	return (i);
}
