/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2022/12/07 19:40:08 by juha             ###   ########seoul.kr  */
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

t_list	*init_envp(char **envp)
{
	t_list	*l;
	char	*str;

	while (*envp)
	{
		str = ft_strdup(*envp);
		ft_lstadd_back(&l, ft_lstnew(str));
		envp++;
	}
	return (l);
}

int	main(int argc, char **argv, char **envp)
{
	char	*sentence;
	t_list	*minishell_envp;

	(void) argc;
	(void) argv;
	init_envp(envp);
	/*
		\ =  시그널 처리
		c =  시그널 처리
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
	return (EXIT_SUCCESS);
}
