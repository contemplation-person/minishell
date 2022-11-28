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

int	main(int argc, char **argv)
{
	char	*option;
	int		option_len;
	int		i;

	if (argc == 1)
		ft_putchar_fd('\n', 1);
	if (argc < 2)
		return (EXIT_SUCCESS);
	option_len = 0;
	option = argv[1];
	if ('-' == *option)
		option_len++;
	while (option[option_len] == 'n')
		option_len++;
	if ((option_len == ft_strlen(option)) == FALSE)
	{
		ft_putstr_fd(argv[1], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	i = 2;
	while (i < argc)
	{
		ft_putstr_fd(argv[i++], STDOUT_FILENO);
		if (i < argc)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if ((option_len == ft_strlen(option)) == FALSE)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
