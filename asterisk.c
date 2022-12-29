// echo Desktop Dowload
#include "42/succes_mission/libft/libft.h"
#include <dirent.h>
#include <stdio.h>

int	find_asterisk(char *sub_token)
{
	while (*sub_token)
	{
		if (*sub_token == '*')
			return (1);
		sub_token++;
	}
	return (0);
}

/*
	*d
	dir_name;

	D*
*/

int	is_same(char *sub_token, char *d_name)
{
	int		i;
	char	**split_token;
	//int		sub_token_len;

	while (*sub_token && *sub_token != '*')
	{
		if (*sub_token++ != *d_name++)
			return (0);
	}
	//sub_token_len = ft_strlen(sub_token);
	//if (sub_token[sub_token_len] == '*')
	//{
	//	while (sub_token_len && sub_token[sub_token_len] != '*')
	//	{
	//		sub_token_len--;
	//	}
	//	if (ft_strncmp(&(sub_token[sub_token_len]), d_name))
	//}
	//asterisk = 0;
	split_token = ft_split(sub_token, '*');
	if (!split_token)
		exit(1);
	i = 0;
	while (split_token[i])
	{
		if (ft_strncmp(split_token[i], d_name, ft_strlen(split_token[i])))
			d_name += ft_strlen(split_token);
		free(split_token[i]);
		i++;
	}
	free(split_token);
/*
	끝에 *가 있으면 끝,
	아니면, 끝에 문자열 확인,
*/
	return (1);
	
/*
	*dddddddd*Ddd
*/
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
	int		check;

	check = 0;
	sub_token = ft_split(token, ' ');
	if (!sub_token)
		exit(1);
	ret = *sub_token;
	if (++sub_token)
	{
		token = ret;
		ret = ft_strjoin(token, ' ');
		free(token);
	}
	else
		return (ret);
	while (sub_token)
	{
		token = ret;
		if (find_asterisk(*sub_token))
		{
			ret = ft_strjoin(token, sub_token);
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
		free(sub_token);
		sub_token++;
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
	printf("result : %s\n", asterisk(token));
	system("leaks a.out");
}