/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/27 15:04:33 by juha             ###   ########seoul.kr  */
=======
/*   Updated: 2022/12/27 18:38:10 by gyim             ###   ########seoul.kr  */
>>>>>>> 8a500e446c1d86948b092176219bad682b47233a
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	is_white_space(char *check_charecter)
{
	int	len;
	int	cmp_len;

	len = ft_strlen(check_charecter);
	cmp_len = 0;
	while (check_charecter && !(8 < *check_charecter && *check_charecter < 14) \
			&& *check_charecter != 32)
	{
		check_charecter++;
		cmp_len++;
	}
	return (cmp_len != len);
}

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

void	signal_handler(int signal_int, struct __siginfo *signint, void *test)
{
	(void)signint;
	(void)test;
	if (signal_int == SIGQUIT)
		return ;
	else if (signal_int == SIGINT)
		exit(1);
	else
		printf("test2 : %d\n",signal_int);
	return ;
}

void	_set_signal(struct sigaction *sa)
{
	sa->sa_flags = SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGQUIT);
	sigaddset(&sa->sa_mask, SIGINT);
	sa->__sigaction_u.__sa_sigaction = signal_handler;
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
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		sentence = readline("MINISHELL : ");
		sigaction(SIGINT, &sa, NULL);
		sigaction(SIGQUIT, &sa, NULL);
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