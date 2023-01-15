/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2023/01/15 22:41:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	minishell_excute(t_env_info_list *minishell_envp_list)
{
	char				*sentence;
	t_fds				fds;

	fds.stdin_fd = dup(STDIN_FILENO);
	fds.stdout_fd = dup(STDOUT_FILENO);
	while (1)
	{
		_set_signal(1);
		sentence = readline("MINISHELL : ");
		if (sentence == NULL)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			return (g_error_code);
		}
		if (sentence && ft_strlen(sentence))
			add_history(sentence);
		if (parsing_excute(sentence, &fds, minishell_envp_list) == -1)
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

	if (argc != 1)
		builtin_error_message("MINISHELL : ", "123", "command not found", 127);
	(void) argv;
	init_list(&minishell_envp_list, envp);
	g_error_code = minishell_excute(&minishell_envp_list);
	return (g_error_code);
}
