/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:10:50 by gyim              #+#    #+#             */
/*   Updated: 2023/01/10 14:42:37 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	smart_join(char	**first_str, char *second_str)
{
	char	*temp;

	temp = *first_str;
	*first_str = ft_strjoin(temp, second_str);
	if (!(*first_str))
		exit(1);
	if (temp)
		free(temp);
}

void	ret_make_asterisk(char *change_token, char **sub_token)
{
	if (!change_token)
		return ;
	free(*sub_token);
	*sub_token = change_token;
}

void	make_asterisk(char **sub_token)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*change_token;

	change_token = NULL;
	dp = opendir(".");
	if (dp == NULL)
		exit(1);
	dirp = readdir(dp);
	while (dirp)
	{
		if (is_same_patten(*sub_token, dirp->d_name))
		{
			if (change_token)
				smart_join(&change_token, " ");
			if (!change_token)
				change_token = ft_strdup(dirp->d_name);
			else
				smart_join(&change_token, dirp->d_name);
		}
		dirp = readdir(dp);
	}
	closedir(dp);
	ret_make_asterisk(change_token, sub_token);
}

static int	find_asterisk(char *sub_token)
{
	if (!sub_token)
		return (0);
	while (*sub_token)
	{
		if (*sub_token == '*')
			return (1);
		sub_token++;
	}
	return (0);
}

char	*asterisk(char *token)
{
	char	**sub_token;
	char	*ret;
	int		i;

	sub_token = ft_split(token, ' ');
	if (!sub_token)
		exit(1);
	i = 0;
	ret = NULL;
	while (sub_token[i])
	{
		if (find_asterisk(sub_token[i]))
			make_asterisk(&(sub_token[i]));
		if (ret)
		{
			smart_join(&ret, " ");
			smart_join(&ret, sub_token[i]);
		}
		else
			ret = ft_strdup(sub_token[i]);
		free(sub_token[i]);
		i++;
	}
	free(sub_token);
	return (ret);
}
