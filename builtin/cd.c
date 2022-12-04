/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:59 by gyim              #+#    #+#             */
/*   Updated: 2022/11/28 15:58:37 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*result;
	int		flag;

	if (argc == 1)
	{
		flag = chdir("$HOME");
		result = getcwd(NULL, 1000000);
		printf("chdir flag : %d\n", flag);
		printf("changed :dir : %s\n", result);
		exit(0);
	}
	flag = chdir(argv[1]);
	result = getcwd(NULL, 1000000);
	printf("chdir flag : %d\n", flag);
	printf("changed :dir : %s\n", result);
	return (0);
}
