/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:59 by gyim              #+#    #+#             */
/*   Updated: 2022/12/24 17:45:59 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
/*
	새로 만들 것.
	input : cd aklsdfj
	return : cd: asdf: No such file or directory
	return value : 1

	input : cd             (공백)
	cdpah = ~/ 
	return :
	return value : 0

	input : cd     //
	cdpah = root
	return : 
	return value : 0



#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	DIR			*dp;
	struct dirent *dirp;

	dp = opendir(".");
	if (dp == NULL)
	{
		printf("NULL");
		return 0;
	}
	dirp = readdir(dp);
	if (dirp == NULL)
	{
		printf("NULL");
		return 0;
	}
	while (dirp)
	{
		printf("ino : %d\n", dirp->d_ino);
		printf("d_name : %s\n", dirp->d_name);
		printf("d_name_len : %d\n", dirp->d_namlen);
		//printf("%d\n", dirp->d_reclen);
		//printf("%d\n", dirp->d_seekoff);
		dirp = readdir(dp);
	}
	closedir(dp);
	if(chdir(".."))
	{
		printf("error\n");
		return 0;
	}
	dp = opendir(".");
	if (dp == NULL)
	{
		printf("NULL");
		return 0;
	}
	dirp = readdir(dp);
	if (dirp == NULL)
	{
		printf("NULL");
		return 0;
	}
	while (dirp)
	{
		printf("ino : %d\n", dirp->d_ino);
		printf("d_name : %s\n", dirp->d_name);
		printf("d_name_len : %d\n", dirp->d_namlen);
		//printf("%d\n", dirp->d_reclen);
		//printf("%d\n", dirp->d_seekoff);
		dirp = readdir(dp);
	}
	closedir(dp);

}%
*/

int	cd(char **excute_str_form)
{
	return (0);
}
