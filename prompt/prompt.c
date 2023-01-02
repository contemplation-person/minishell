/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2023/01/02 13:25:47 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static void	init_list(t_env_info_list *list, char **envp)
{
	int	i;

	i = 0;
	ft_memset(list, 0, sizeof(list));
	while (envp[i])
	{
		add_env_list(list, envp[i], ENV);
		i++;
	}
}

// void	signal_handler(int signal_int)
// {
// 	if (signal_int == SIGINT)
// 	{
// 		write(1, "\n", 1);
// 		rl_replace_line("", 1);
// 		rl_on_new_line();
// 		rl_redisplay();
// 		g_error_code = 130;
// 	}
// }

// void	_set_signal(struct sigaction *sa)
// {
// 	sa->sa_flags = SIGINFO;
// 	sigemptyset(&sa->sa_mask);
// 	sigaddset(&sa->sa_mask, SIGQUIT);
// 	sigaddset(&sa->sa_mask, SIGINT);
// 	sa->__sigaction_u.__sa_handler = signal_handler;
// 	signal(SIGQUIT, SIG_IGN);
// }

int	minishell_excute(t_env_info_list *minishell_envp_list)
{
	char				*sentence;

	while (1)
	{
		// signal(SIGINT, signal_handler);
		sentence = readline("MINISHELL : ");
		if (sentence == NULL)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			return (g_error_code);
		}
		if (sentence && ft_strlen(sentence))
			add_history(sentence);
		if (parsing_excute(sentence, minishell_envp_list) == -1)
		{
			free(sentence);
			break ;
		}
		free(sentence);
		// system("leaks minishell");
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_env_info_list		minishell_envp_list;
	// struct sigaction	sa;

	if (argc != 1)
		builtin_error_message("bash", "123", "command not found", 127);
	(void) argv;
	// _set_signal(&sa);
	init_list(&minishell_envp_list, envp);
	g_error_code = minishell_excute(&minishell_envp_list);
	return (g_error_code);
}
