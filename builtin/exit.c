/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:28:00 by juha              #+#    #+#             */
/*   Updated: 2022/12/08 12:41:52 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/*
	Exit the shell, returning a status of n to the shell’s parent. 
	If n is omitted, the exit status is that of the last command executed. 
	Any trap on EXIT is executed before the shell terminates.
	
	exit number -> exit number
	exit number(131) -> exit (131);
	argc > 2 && first char == not digit -> too many argument(2) -> exit(2);
	argc > 2 && first char == digit && second char == not digit -> too many argument(2) -> not exit and 127;

	exit 

*/
int	builtin_exit(int argc, char **argv)
{
	if (1 < argc)
	{
		ft_putstr_fd("exit : ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(2);
	}
	else
	{
		ft_putstr_fd("exit", STDIN_FILENO);
		exit(EXIT_SUCCESS);
	}
}