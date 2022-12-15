/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2022/12/14 14:18:32 by juha             ###   ########seoul.kr  */
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

	/*
		\ =  시그널 처리
		c =  시그널 처리
	*/
/*
*/
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
	// system("leaks a.out");
	return (EXIT_SUCCESS);
}