/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2023/01/09 13:21:54 by gyim             ###   ########seoul.kr  */
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
		g_error_code = 130;
	}
}

void	signal_handler2(int signal_int)
{
	if (signal_int == SIGINT)
	{
		write(1, "\n", 1);
		rl_redisplay();
	}
	else if (signal_int == SIGQUIT)
	{
		ft_putendl_fd("Quit: 3", STDERR_FILENO);
		g_error_code = 131;
	}
}

void	_set_signal(struct sigaction *sa, int flag)
{
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGQUIT);
	sigaddset(&sa->sa_mask, SIGINT);
	if (flag == 1)
	{
		sa->sa_handler = signal_handler;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
	}
	else
	{
		sa->sa_handler = signal_handler2;
		signal(SIGQUIT, signal_handler2);
		signal(SIGINT, signal_handler2);
	}
}

int	minishell_excute(t_env_info_list *minishell_envp_list, struct sigaction *sa)
{
	char				*sentence;

	while (1)
	{
		_set_signal(sa, 1);
		sentence = readline("MINISHELL : ");
		if (sentence == NULL)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			return (g_error_code);
		}
		if (sentence && ft_strlen(sentence))
			add_history(sentence);
		_set_signal(sa, 0);
		if (parsing_excute(sentence, minishell_envp_list) == -1)
		{
			free(sentence);
			break ;
		}
		free(sentence);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_env_info_list		minishell_envp_list;
	struct sigaction	sa;

	if (argc != 1)
		builtin_error_message("MINISHELL : ", "123", "command not found", 127);
	(void) argv;
	init_list(&minishell_envp_list, envp);
	g_error_code = minishell_excute(&minishell_envp_list, &sa);
	return (g_error_code);
}
