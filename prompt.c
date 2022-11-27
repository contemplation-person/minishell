/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:13:33 by juha              #+#    #+#             */
/*   Updated: 2022/11/27 23:52:49 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char	*sentence;

	while (1)
	{
		sentence = readline("a : ");
		if (sentence == NULL)
			return (EXIT_SUCCESS); // 에러코드 정리 필요.
		/* 토큰화 */
		add_history(sentence);
		free(sentence);
		rl_redisplay();
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	return (EXIT_SUCCESS);
}