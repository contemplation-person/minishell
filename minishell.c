/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:01:26 by juha              #+#    #+#             */
/*   Updated: 2022/11/28 15:17:44 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
	readline()은 null이 들어오거나 \0가 들어올 때 시그널 처리를 한다.
*/

int	main()
{
	char	*sentence;

	while (42)
	{
		sentence = readline("gamshell$ ");
		if (sentence == NULL)
		{
			free(sentence);
			printf("exit\n");
			return (127); // 에러코드 정리 필요.
		}
		if (*sentence != '\n')
			add_history(sentence);
		rl_replace_line("", 0);
		// rl_on_new_line();
		// rl_redisplay();
		/* 토큰화 */
		free(sentence);
	}
	return (EXIT_SUCCESS);
}
