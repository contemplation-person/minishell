/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:20:36 by juha              #+#    #+#             */
/*   Updated: 2022/11/23 08:20:36 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	check_option(int *option, char **excute_str_form, int *i, int argc)
{
	int		option_len;
	char	*option_str;

	while (*i < argc)
	{
		option_len = 0;
		option_str = excute_str_form[*i];
		if ('-' != *option_str)
			break ;
		if ('-' == *option_str)
			(option_len)++;
		while ((option_str)[option_len] == 'n')
			(option_len)++;
		if ((option_len) == (int)ft_strlen((option_str)) == FALSE)
		{
			break ;
			ft_putstr_fd(excute_str_form[*i], STDOUT_FILENO);
			ft_putchar_fd(' ', STDOUT_FILENO);
		}
		*option = TRUE;
		(*i)++;
	}
}

t_bool	echo(char **excute_str_form)
{
	int		option;
	int		i;
	int		argc;

	g_error_code = 0;
	argc = cnt_argc(excute_str_form);
	option = FALSE;
	if (argc == 1)
		ft_putchar_fd('\n', 1);
	else
	{
		i = 1;
		check_option(&option, excute_str_form, &i, argc);
		while (i < argc)
		{
			ft_putstr_fd(excute_str_form[i++], STDOUT_FILENO);
			if (i < argc)
				ft_putchar_fd(' ', STDOUT_FILENO);
		}
		if (option == FALSE)
			ft_putstr_fd("\n", STDOUT_FILENO);
	}
	return (TRUE);
}
