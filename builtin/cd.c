/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:59 by gyim              #+#    #+#             */
/*   Updated: 2022/12/27 08:20:07 by gyim             ###   ########seoul.kr  */
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
	}
	else if (excute_str_cnt == 2) // 2개 일때 상대, 절대.
	{
		pwd = NULL;
		if (excute_str_form[1][0] == '~')
		{
			pwd = ft_strjoin(home, )
		}
		else
			chdir(excute_str_form[1]);
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
}
