// echo Desktop Dowload
#include "42/succes_mission/libft/libft.h"
#include <dirent.h>
#include <stdio.h>

//succes!!
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

//success!!!
int	is_same_patten(char *sub_token, char *d_name)
{
	int	sub_idx;
	int	d_idx;

	sub_idx = 0;
	d_idx = 0;
	//printf("%s || %s\n",sub_token, d_name);
	while (d_name[d_idx])
	{
		//printf("while = s : %c\t| d : %c\n", sub_token[sub_idx] , d_name[d_idx] );
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
	//printf("result = s : %c\t| d : %c\n", sub_token[sub_idx] , d_name[d_idx] );
	return (d_name[d_idx] == sub_token[sub_idx]);
}

void	make_asterisk(char **sub_token)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*change_token;
	char			*temp;

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
			{
				temp = change_token;
				change_token = ft_strjoin(temp, " ");
				if (!change_token)
					exit(1);
				if (temp)
					free(temp);
			}
			temp = change_token;
			//printf("t : %p, dir : %p\n", temp, dirp->d_name);
			if (!temp)
				change_token = ft_strdup(dirp->d_name);
			else
			{
				change_token = ft_strjoin(temp, dirp->d_name);
				if (!change_token)
					exit(1);
				if (temp)
					free(temp);
			}
		}
		dirp = readdir(dp);
	}
	closedir(dp);
	printf("make result : %s\n", change_token);
	if (change_token)
	{
		free(*sub_token);
		*sub_token = change_token;
	}
}

char	*asterisk(char *token)
{
	char	**sub_token;
	char	*ret;
	int		i;

	i = 0;
	sub_token = ft_split(token, ' ');
	while (sub_token[i])
	{
		printf("asterisk : %s\n", sub_token[i]);
		if (find_asterisk(sub_token[i]))
		{
			/*
				original sub_token free and new_token ret;
			*/
			make_asterisk(&(sub_token[i]));
		}
		i++;
	}
	/*
	//check function
	printf("done : ");
	i = 0;
	while (sub_token[i])
	{
		printf("%s", sub_token[i++]);
	}
	i = 0;
	while (sub_token[i])
	{
		free(sub_token[i++]);
	}
	free(sub_token);

		ret join all sub_token
	*/
	return (ft_strdup("ok"));
}

int main()
{
	char	*token = "0. echo\n1. d*d \n2. *d \n3. *d* \n4. d* \n";
	char	*asterisk_str = asterisk(token);
/*
		downloadd

		d*d

		*d
		*d*
		d*

		dcd
		dd
		cdd
*/
	//char *dir = "libft.a";
	//char *token = ".*";
	//printf("input - s : %s\t|d : %s\n\n", token, dir);
	//printf("result : %s\n", (is_same_patten(token, dir) ? "true" : "false"));
	printf("\nresult :\n\n%s\n\n", asterisk_str);
	printf("asterp : %p\n", asterisk_str);
	free(asterisk_str);
	system("leaks a.out");
}