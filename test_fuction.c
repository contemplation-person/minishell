/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fuction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:49:53 by juha              #+#    #+#             */
/*   Updated: 2022/11/21 20:02:07 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char *print;
	while (print = readline("test : "))
	{
		printf("%s",print);
		free(print);
		rl_on_new_line();
	}
}