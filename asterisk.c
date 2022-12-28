// echo Desktop Dowload
#include "42/succes_mission/libft/libft.h"
#include <dirent.h>

int	find_asterisk(char *token)
{
	while (*token)
	{
		if (*token == '*')
			return (1);
		token++;
	}
	return (0);
}

/*
	echo *D D*

	1.	sub_token = split(token);
		*D
		D*
*/
int	match_token(char *token, char *d_name)
{
	int	i;
	int j;

	i = 0;
	j = 0;
}

char	*change_asterisk(char *token)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*ret;
	char			*temp;

	ret = ft_strdup("");
	if (!ret)
		exit(1);
	dp = opendir(".");
	if (dp != NULL)
	{
		dirp = readdir(dp);
		while (dirp)
		{
			temp = ret;
			if (match_token(token, dirp->d_name))
			{
				ret = ft_strjoin(temp, dirp->d_name);
				if (!ret)
					exit(1);
				free(temp);
			}
			printf("d_name : %s\n", dirp->d_name);		//
			dirp = readdir(dp);
			if (dirp)
			{
				temp = ret;
				ret = ft_strjoin(temp, " ");
				free(temp);
			}
		}
		closedir(dp);
	}
	return (ret);
/*
	asterisk가 있으면 파일 확인,
*/
}

/*
	echo *D D*

	1.	sub_token = split(token);
		echo
		*
		D*
*/
char	*asterisk(char *token)
{
	char	**sub_token;
	char	*ret;
	char	*temp;
	char	*change_word;
	int		i;

	i = 0;
	sub_token = ft_split(token, " ");
	ret = ft_strdup("");
	if (!sub_token || !ret)
		exit(1);
	while (sub_token[i])
	{
		temp = ret;
		if (i != 0 && find_asterisk(sub_token[i]))
		{
			change_word = change_asterisk(sub_token[i]);
			ret = ft_strjoin(temp, change_word);
			free(change_word);
		}
		else
			ret = ft_strjoin(temp, sub_token[i]);
		if (!ret)
			exit(1);
		free(temp);
		free(sub_token[i++]);
		if (sub_token[i])
		{
			temp = ret;
			ret = ft_strjoin(temp, " ");
			if (!ret)
				exit(1);
			free(temp);
		}
	}
	free(sub_token);
	return (ret);
}

int main()
{
	char	*token = "echo * D";
	printf("%s\n", asterisk(token));
}