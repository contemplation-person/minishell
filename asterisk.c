// echo Desktop Dowload
#include "42/succes_mission/libft/libft.h"
#include <dirent.h>
#include <stdio.h>

int	find_asterisk(char *sub_token)
{
	if (!sub_token)
		return (1);
	while (*sub_token)
	{
		if (*sub_token == '*')
			return (1);
		sub_token++;
	}
	return (0);
}

int	is_same(char *sub_token, char *d_name)
{
	/*
		download

		*d
		*d*
		d*
	*/
	int	px;
	int	nx;
	int	total_p_len;
	int total_n_len;
	char c;

	px = 0;
	nx = 0;
	total_p_len = ft_strlen(sub_token);
	total_n_len = ft_strlen(d_name);
	while (px < total_p_len || nx < total_n_len)
	{
		if (px < total_p_len)
		{
			c = sub_token[px];
			if (nx < total_n_len && d_name[nx] == c)
			{
				px++;
				nx++;
				continue ;
			}
			else if (c == '*')
			{
				if (nx < total_n_len)
				{
					px++;
					nx++;
					continue ;
				}
			}
			else
				return (0);
		}
	}
	return (1);
}

char	*make_asterisk(char *sub_token)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*ret;
	char			*temp;

	ret = NULL;
	dp = opendir(".");
	if (dp == NULL)
		exit(1);
	dirp = readdir(dp);
	if (dirp == NULL)
		exit(1);
	while (dirp)
	{
		if (is_same(sub_token, dirp->d_name))
		{
			temp = ret;
			ret = ft_strjoin(temp, " ");
			if (!ret)
				exit(1);
			free (temp);

			temp = ret;
			ret = ft_strjoin(temp, dirp->d_name);
			if (!ret)
				exit(1);
			free(temp);
		}
		printf("d_name : %s\n", dirp->d_name);
		//printf("number : %d\n", dirp->d_seekoff);
		dirp = readdir(dp);
	}
	closedir(dp);
	if (ret == NULL)
	{
		ret = ft_strdup(sub_token);
		if (!ret)
			exit(1);
	}
	return (ret);
}

char	*asterisk(char *token)
{
	char	*ret;
	char	**sub_token;
	char	*temp;

	sub_token = ft_split(token, ' ');
	if (!sub_token)
		exit(1);
	ret = *sub_token;
	if (sub_token)
	{
		free(sub_token++);
		token = ret;
		ret = ft_strjoin(token, " ");
		free(token);
	}
	else
		return (ret);
	while (*sub_token)
	{
		token = ret;
		if (find_asterisk(*sub_token))
		{
			ret = ft_strjoin(token, *sub_token);
			if (!ret)
				exit(1);
		}
		else
		{
			temp = make_asterisk(*sub_token);
			ret = ft_strjoin(token, temp);
			if (!ret)
				exit(1);
			free(temp);
		}
		free(token);
		free(*sub_token);
		++sub_token;
		if (sub_token)
		{
			token = ret;
			ret = ft_strjoin(token, " ");
			free(token);
		}
	}
	return (ret);
}

int main()
{
	char	*token = "echo * D";
	char	*asterisk_str = asterisk(token);

	printf("\nresult : %s\n\n", asterisk_str);
	free(asterisk_str);
	system("leaks a.out");
}