/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/28 17:07:27 by juha             ###   ########seoul.kr  */
=======
/*   Updated: 2022/12/28 14:31:27 by gyim             ###   ########seoul.kr  */
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0
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

void	signal_handler(int signal_int)
{
<<<<<<< HEAD
	if (signal_int == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_error_code = 130;
	}
=======
	(void)signint;
	(void)test;
	if (signal_int == SIGQUIT)
		return ;
	else if (signal_int == SIGINT)
	{
		g_error_code = 1;
		write(2, "\n", 1);
	}
	else
		printf("test2 : %d\n",signal_int);
	return ;
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0
}

void	_set_signal(struct sigaction *sa)
{
	sa->sa_flags = SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGQUIT);
	sigaddset(&sa->sa_mask, SIGINT);
	sa->__sigaction_u.__sa_handler = signal_handler;
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **envp)
{
	char				*sentence;
	t_env_info_list		minishell_envp_list;
	struct sigaction	sa;

	if (argc != 1)
		builtin_error_message("bash", "123", "command not found", 127);
	(void) argv;
	_set_signal(&sa);
	init_list(&minishell_envp_list, envp);
	while (1)
	{
		signal(SIGINT, signal_handler);
		sentence = readline("MINISHELL : ");
		if (sentence == NULL)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			return (g_error_code);
		}
		if (sentence && ft_strlen(sentence))
			add_history(sentence);
		if (parsing_excute(sentence, &minishell_envp_list) == -1)
		{
			free(sentence);
			break ;
		}
		free(sentence);
		//system("leaks minishell");
	}
}