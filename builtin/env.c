/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:28:24 by juha              #+#    #+#             */
/*   Updated: 2022/12/02 12:48:20 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;

	if (argc > 2)
	{
		ft_putstr_fd("pwd : too many arguments", STDERR_FILENO);
		return (1);
	}
	else if (argc == 1)
	{
		while (*envp)
		{
			ft_putstr_fd(*envp, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			envp++;
		}
	}
	else
		ft_putstr_fd(getenv(argv[1]), STDOUT_FILENO);
		/*ㅇㅣㄴㅈㅏ 값값이  파파일일이이면  경경로로*/
	return (0);
}