/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2022/12/13 19:48:22 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
/*
	readline()은 null이 들어오거나 \0가 들어올 때 시그널 처리를 한다.
*/

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
	while (envp[i])
	{
		add_env_list(list, envp[i], ENV);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char			*sentence;
	t_env_info_list	minishell_envp_list;

	(void) argc;
	(void) argv;
	(void) sentence;
	ft_memset(&minishell_envp_list, 0, sizeof(t_env_info_list));
	init_list(&minishell_envp_list, envp);
// check envp
	print_envp(minishell_envp_list, ENV);
	ft_putendl_fd("--------------------", STDOUT_FILENO);
	delete_one_list(&minishell_envp_list, "USER");
	print_envp(minishell_envp_list, ENV);
	// remove_env_list(&minishell_envp);
	// ft_putstr_fd("------------\n",1);
	// print_envp(minishell_envp);
	system("leaks a.out");
// check envp

	/*
		\ =  시그널 처리
		c =  시그널 처리
	*/
/*
	while (1)
	{
		sentence = readline("no shell : ");
		ft_putstr_fd(sentence, STDERR_FILENO);
		if (sentence == NULL)
			return (EXIT_SUCCESS);
		if (sentence && ft_strlen(sentence))
			add_history(sentence);
		free(sentence);
	}
	return (EXIT_SUCCESS);
*/
}