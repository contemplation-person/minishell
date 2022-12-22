/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:28:00 by juha              #+#    #+#             */
/*   Updated: 2022/12/22 21:47:04 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
excute_str = exit 123d
return value = 2
error_massage = exit\nbash: exit: 123d: numeric argument required

undo_part

excute_str = exit 123 123
return value = 1
error_massage = bash: exit: too many arguments

excute_str = exit
return value = 0
massage = exit\n

excute_str = exit number
return value = number
massage = exit

1. check first
*/
int	builtin_exit(char **excute_str_form)
{
	int	word_cnt;

	word_cnt = 0;
	while (excute_str_form[word_cnt++])
		;
	if (1 < word_cnt)
	{
		ft_putstr_fd("exit : ", STDERR_FILENO);
		ft_putstr_fd(excute_str_form[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(2);
	}
	else
	{
		ft_putstr_fd("exit", STDIN_FILENO);
		exit(g_error_code % 256);
	}
}
