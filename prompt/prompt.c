/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2022/12/28 15:35:22 by juha             ###   ########seoul.kr  */
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

void	signal_handler(int signal_int)
{
	if (signal_int == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	_set_signal(struct sigaction *sa)
{
	sa->sa_flags = SIGINFO;
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
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
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