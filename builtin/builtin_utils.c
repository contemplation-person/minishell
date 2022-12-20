/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:36:45 by juha              #+#    #+#             */
/*   Updated: 2022/12/20 18:30:16 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_bool	builtin_error_message(char *builtin_name, char *error, char *message)
{
	ft_putstr_fd(builtin_name, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	//error_code = 1;
	return (1);
}