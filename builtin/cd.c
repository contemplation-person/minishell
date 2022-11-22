/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:59 by gyim              #+#    #+#             */
/*   Updated: 2022/11/22 20:30:47 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*curr_dir;

	if (argc > 2)
	{
		write(2, "Error message\n", 14);
		exit(1);
	}
	curr_dir = getcwd(NULL, 10000);
	printf("curr_dir : %s\n", curr_dir);
	free(curr_dir);
	return (0);
}
