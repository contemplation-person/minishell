/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:42/Piscine/C/C04/ex02/ft_putnbr.c
/*   Created: 2022/01/12 17:49:38 by juha              #+#    #+#             */
/*   Updated: 2022/01/12 17:50:46 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_change_negative(int nb)
{
	if (nb >= 0)
	{
		return (nb);
	}
	else
	{
		return (-nb);
	}
}

void	ft_print(unsigned int nb)
{
	char	c;

	if (nb / 10)
	{
		ft_print(nb / 10);
		c = nb % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = nb % 10 + '0';
		write(1, &c, 1);
		return ;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	absolute_nb;

	absolute_nb = ft_change_negative(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	ft_print (absolute_nb);
=======
/*   Created: 2022/11/22 19:56:59 by gyim              #+#    #+#             */
/*   Updated: 2022/12/27 14:22:22 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <dirent.h>
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

}
*/

t_env_info	*find_env(t_env_info_list *envp, char *key)
{
	t_env_info	*ret;

	ret = envp->env_info;
	while (ret)
	{
		if (ft_strncmp(ret->key, key, ft_strlen(key)))
			break ;
		ret = ret->next;
	}
	return (ret);
}

t_bool	builtin_cd(t_env_info_list *minishell_envp, char **excute_str_form)
{
	char		*old_pwd;
	int			excute_str_cnt;
	char		*home;
	char		*pwd;

	excute_str_cnt = cnt_argc(excute_str_form);
	/*
		절대 상대 경로만...
		home 이 있으면 홈으로, 없으면 getenv로.
	*/
	if (find_env(minishell_envp, "HOME"))
		home = find_env(minishell_envp, "HOME")->value;
	else
		home = getenv("HOME");
	old_pwd = getcwd(NULL, 1);
	if (excute_str_cnt == 1)
	{
		if (!find_env(minishell_envp, "HOME"))
		{
			free(old_pwd);
			builtin_error_message("cd", "HOME NOT set", "", 1);
			return (FALSE);
		}
		chdir(home);
		g_error_code = 0;
	}
	else if (excute_str_cnt == 2) // 2개 일때 상대, 절대.
	{
		pwd = NULL;
		if (excute_str_form[1][0] == '~')
		{
			pwd = ft_strjoin(home, "/");
			pwd = ft_strjoin(pwd, excute_str_form[1] + 1);
		}
		else
			chdir(excute_str_form[1]);
		g_error_code = 0;
	}
	if (find_env(minishell_envp, "OLDPWD"))
	{
		free(find_env(minishell_envp, "OLDPWD")->value);
		(find_env(minishell_envp, "OLDPWD")->value) = old_pwd;
	}
	else
		free(old_pwd);
	if (find_env(minishell_envp, "PWD"))
	{
		free(find_env(minishell_envp, "PWD")->value);
		(find_env(minishell_envp, "PWD")->value) = getcwd(NULL, 1);
	}
	return (TRUE);
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0:builtin/cd.c
}
