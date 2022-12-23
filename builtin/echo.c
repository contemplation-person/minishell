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

#include "../libft/libft.h"

enum e_bool
{
	FALSE,
	TRUE,
};

int	cnt_argc(char **excute_str_form)
{
	int	i;

	i = 0;
	while (excute_str_form[i])
		i++;
	return (i);
}

int	echo(char **excute_str_form)
{
	char	*option;
	int		option_len;
	int		i;
	int		argc;

	argc = cnt_argc(excute_str_form);
	if (argc == 1)
		ft_putchar_fd('\n', 1);
	if (argc < 2)
		return (EXIT_SUCCESS);
	option_len = 0;
	option = excute_str_form[1];
	if ('-' == *option)
		option_len++;
	while (option[option_len] == 'n')
		option_len++;
	if ((option_len == ft_strlen(option)) == FALSE)
	{
		ft_putstr_fd(excute_str_form[1], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	i = 2;
	while (i < argc)
	{
		ft_putstr_fd(excute_str_form[i++], STDOUT_FILENO);
		if (i < argc)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if ((option_len == ft_strlen(option)) == FALSE)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
