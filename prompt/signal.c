/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:15:47 by gyim              #+#    #+#             */
/*   Updated: 2023/01/17 18:59:44 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	signal_handler(int signal_int)
{
	if (signal_int == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	g_error_code = 128 + signal_int;
}

void	signal_handler2(int signal_int)
{
	if (signal_int == SIGINT)
	{
		write(1, "\n", 1);
		rl_redisplay();
	}
	else if (signal_int == SIGQUIT)
		ft_putendl_fd("Quit: 3", STDERR_FILENO);
	g_error_code = 128 + signal_int;
}

void	signal_handler3(int signal_int)
{
	if (signal_int == SIGINT)
	{
		write(1, "\n", 1);
		rl_redisplay();
	}
	g_error_code = 128 + signal_int;
}

void	_set_signal(int flag)
{
	struct sigaction	sa;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	if (flag == 1)
	{
		sa.sa_handler = signal_handler;
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (flag == 2)
	{
		sa.sa_handler = signal_handler2;
		signal(SIGINT, signal_handler2);
		signal(SIGQUIT, signal_handler2);
	}
	else if (flag == 3)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, signal_handler3);
	}
}
