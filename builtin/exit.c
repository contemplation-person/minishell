/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:28:00 by juha              #+#    #+#             */
/*   Updated: 2023/01/17 15:07:17 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

	word_cnt = cnt_argc(excute_str_form);
	if (word_cnt > 1 && is_error_word(excute_str_form[1]))
	{
		builtin_error_message("exit", excute_str_form[1], \
								"numeric argument required", 2);
		exit (g_error_code);
	}
	else if (word_cnt == 2)
		exit(ft_atoi(excute_str_form[1]));
	else if (word_cnt > 2)
	{
		if (!g_error_code)
			g_error_code = 1;
		builtin_error_message("exit", "", "too many arguments", g_error_code);
	}
	else
		exit(0);
	return (g_error_code);
}
