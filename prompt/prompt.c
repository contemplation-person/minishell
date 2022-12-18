/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2022/12/19 08:15:30 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	error_code = 0;

int	is_white_space(char *check_charecter)
{
	int	len;
	int	cmp_len;

	len = ft_strlen(check_charecter);
	cmp_len = 0;
	while (check_charecter \
		&& !(8 < *check_charecter && *check_charecter < 14) \
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
		error_code = 1;
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

	(void) sentence;
	_set_signal(&sa);
	if (argc != 1)
		return (1);
	(void) argv;
	ft_memset(&minishell_envp_list, 0, sizeof(t_env_info_list));
	init_list(&minishell_envp_list, envp);
	print_envp(minishell_envp_list, ENV);
	//while (42)
	//{
	//	sentence = readline("no shell : ");
	//	sigaction(SIGINT, &sa, NULL);
	//	sigaction(SIGQUIT, &sa, NULL);
	//	ft_putstr_fd(sentence, STDERR_FILENO);
	//	if (sentence == NULL)
	//		error_code = EXIT_SUCCESS;
	//	else if (ft_strlen(sentence))
	//		add_history(sentence);
	//	free(sentence);
	//}
	// system("leaks a.out");
	return (EXIT_SUCCESS);
}