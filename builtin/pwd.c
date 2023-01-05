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

void	builtin_pwd(char **excute_str_form)
{
	int		i;
	char	*str;

	i = cnt_argc(excute_str_form);
	if (i != 1)
		return (builtin_error_message("bash",
				"pwd", "too many arguments", 127));
	str = NULL;
	str = getcwd(str, 1);
	ft_putendl_fd(str, STDOUT_FILENO);
	g_error_code = 0;
}
