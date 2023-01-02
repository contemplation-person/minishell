/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:57 by juha              #+#    #+#             */
/*   Updated: 2023/01/02 23:53:00 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <dirent.h> 

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

int	is_same_patten(char *sub_token, char *d_name)
{
	int	sub_idx;
	int	d_idx;

	sub_idx = 0;
	d_idx = 0;
	while (d_name[d_idx])
	{
		if (sub_token[sub_idx] == d_name[d_idx])
		{
			++sub_idx;
			++d_idx;
			continue ;
		}
		else if (sub_token[sub_idx] == '*')
		{
			if (sub_token[sub_idx])
				++sub_idx;
		}
		else if (sub_token[sub_idx] != d_name[d_idx])
		{
			if (!sub_idx)
				return (0);
			else if (sub_token[sub_idx - 1] == '*')
				d_idx++;
			else
			{
				while (sub_idx && sub_token[sub_idx - 1] != '*')
					--sub_idx;
			}
		}
		else
			++d_idx;
	}
	while (sub_token[sub_idx] == '*')
		sub_idx++;
	return (d_name[d_idx] == sub_token[sub_idx]);
}

static void	smart_join(char	**first_str, char **second_str)
{
	char	*temp;

	if (!*second_str)
		return ;
	temp = *first_str;
	*first_str = ft_strjoin(temp, second_str);
	if (!(*first_str))
		exit(1);
	if (temp)
		free(temp);
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
	while (change_token == NULL || dirp)
	{
		dirp = readdir(dp);
		if (is_same_patten(*sub_token, dirp->d_name))
		{
			if (change_token)
				smart_join(&change_token, &" ");
			if (!change_token)
				change_token = ft_strdup(dirp->d_name);
			else
				smart_join(change_token, dirp->d_name);
		}
	}
	if (closedir(dp) == change_token)
		return ;
	free(*sub_token);
	*sub_token = change_token;
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
			smart_join(ret, &" ");
			smart_join(ret, sub_token[i]);
		}
		else
			ret = ft_strdup(sub_token[i]);
		free(sub_token[i]);
		i++;
	}
	free(sub_token);
	return (ret);
}
