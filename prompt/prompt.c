/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2022/12/21 14:59:37 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

// int	is_white_space(char *check_charecter)
// {
// 	int	len;
// 	int	cmp_len;

// 	len = ft_strlen(check_charecter);
// 	cmp_len = 0;
// 	while (check_charecter && !(8 < *check_charecter && *check_charecter < 14) \
// 			&& *check_charecter != 32)
// 	{
// 		check_charecter++;
// 		cmp_len++;
// 	}
// 	return (cmp_len != len);
// }

void	split_key_value(char *env, char **key, char **value)
{
	int	key_len;

	key_len = 0;
	while (env[key_len])
	{
		if (env[key_len++] == '=')
			break ;
	}
	*key = ft_substr(env, 0, key_len);
	if (*key)
		return ;
	if (!key_len)
	{
		free(*key);
		*key = NULL;
		return ;
	}
	*value = ft_substr(env, key_len, ft_strlen(env));
}
static void	init_list(t_list *list, char **envp)
{
	int	i;
	char *key;
	char *value;

	i = 0;
	while (envp[i])
	{
		split_key_value(envp[i], key, value);
		ft_lstadd_back(&list, ft_lstnew(new_env_node(key, value)));
		if (*key && !(*value))
			free(value);
		i++;
	}
}

// void	signal_handler(int signal_int, struct __siginfo *signint, void *test)
// {
// 	if (signal_int == SIGQUIT)
// 		return ;
// 	else if (signal_int == SIGINT)
// 		exit(1);
// 	else
// 		printf("test2 : %d\n",signal_int);
// 	return ;
// }

// void	_set_signal(struct sigaction *sa)
// {
// 	sa->sa_flags = SIGINFO;
// 	sigemptyset(&sa->sa_mask);
// 	sigaddset(&sa->sa_mask, SIGQUIT);
// 	sigaddset(&sa->sa_mask, SIGINT);
// 	sa->__sigaction_u.__sa_sigaction = signal_handler;
// }

int	main(int argc, char **argv, char **envp)
{
	char				*sentence;
	t_list				*env_list;
	// struct sigaction	sa;

	// _set_signal(&sa);
	if (argc != 1)
		return (1);
	(void) argv;
	init_list(env_list, envp);
	//while (1)
	//{
	//	sentence = readline("no shell : ");
	//	// sigaction(SIGINT, &sa, NULL);
	//	// sigaction(SIGQUIT, &sa, NULL);
	//	// ft_putstr_fd(sentence, STDERR_FILENO);
	//	if (sentence == NULL)
	//		return (EXIT_SUCCESS);
	//	if (sentence && ft_strlen(sentence))
	//		add_history(sentence);
	//	if (parsing_excute(sentence, &minishell_envp_list) == -1)
	//	{
	//		free(sentence);
	//		break ;
	//	}
	//	free(sentence);
	//}
	//system("leaks minishell");
	//return (EXIT_SUCCESS);
}