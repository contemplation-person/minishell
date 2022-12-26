/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:28:00 by juha              #+#    #+#             */
/*   Updated: 2022/12/26 15:35:21 by juha             ###   ########seoul.kr  */
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
t_bool	is_error_word(char *word)
{
	while (*word)
	{
		if (!ft_isdigit(*word))
			return (TRUE);
		word++;
	}
	return (FALSE);
}

int	builtin_exit(char **excute_str_form)
{
	int	word_cnt;

	word_cnt = 0;
	while (excute_str_form[word_cnt])
		word_cnt++;
	if (word_cnt == 2 && is_error_word(excute_str_form[1]))
	{
		builtin_error_message("exit", excute_str_form[1], "numeric argument required", 2);
		exit (g_error_code);
	}
	else if (word_cnt > 2)
	{
		builtin_error_message("exit", "", "too many arguments", 1);
	}
	else if (word_cnt == 2)
		exit(ft_atoi(excute_str_form[1]));
	else
		exit(0);
}
