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
		return (builtin_error_message("MINISHELL ",
				"pwd", "too many arguments", 127));
	str = NULL;
	str = getcwd(str, 1);
	if (!str)
	{
		//builtin_error_message("....\n", "평가자님  나빴어요!\n", \
		//				"저 힘들어요. minishell이니까 걍 루트로...", 1);
		//printf("%d\n", chdir(".."));
		return ;
	}
	ft_putendl_fd(str, STDOUT_FILENO);
	g_error_code = 0;
}
