/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2022/12/21 19:45:57 by juha             ###   ########seoul.kr  */
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
	(void) signal_int;
	rl_on_new_line();
	rl_redisplay();
	return ;
}

void	_set_signal(struct sigaction *sa)
{
	sa->sa_flags = 0;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGQUIT);
	sigaddset(&sa->sa_mask, SIGINT);
	sa->__sigaction_u.__sa_handler = signal_handler;
}

int	main(int argc, char **argv, char **envp)
{
	char				*sentence;
	t_env_info_list		minishell_envp_list;
	struct sigaction	sa;

	_set_signal(&sa);
	if (argc != 1)
		builtin_error_message("bash", "123", "command not found", 127);
	(void) argv;
	init_list(&minishell_envp_list, envp);
	while (1)
	{
		signal(SIGQUIT, signal_handler);
		signal(SIGINT, signal_handler);
		rl_redisplay();
		sentence = readline("MINISHELL : ");
		ft_putstr_fd(sentence, STDERR_FILENO);
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
	system("leaks minishell");
}