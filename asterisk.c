// echo Desktop Dowload
#include "42/succes_mission/libft/libft.h"
#include <dirent.h>
#include <stdio.h>

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
	int	sub_idx;
	int	d_idx;

	sub_idx = 0;
	d_idx = 0;
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("input : sub_token - ", 2);
	ft_putstr_fd(sub_token, 2);
	ft_putstr_fd(" | d_name - ", 2);
	ft_putstr_fd(d_name, 2);
	ft_putstr_fd("\n", 2);
	while (sub_token[sub_idx] && d_name[d_idx])
	{
		ft_putstr_fd("result value : sub - ", 2);
		ft_putchar_fd(sub_token[sub_idx], 2);
		ft_putstr_fd(" d_name - ", 2);
		ft_putchar_fd(d_name[d_idx], 2);
		ft_putstr_fd("\n", 2);
		// ownloadd *d
		if (sub_token[sub_idx] == d_name[d_idx])
		{
			sub_token++;
			d_name++;
			continue ;
		}
		else if (sub_token[sub_idx] == '*')
		{
			sub_idx++;
			continue ;
		}
		else
		{
			sub_idx = 0;
		}
		d_idx++;
		if (!(sub_token[sub_idx]))
		{
			while (d_name[d_idx] && (d_name[d_idx] == *(sub_token + sub_idx - 1)))
				d_idx++;
		}
	}
	printf("result = d : %c | s : %c\n", d_name[d_idx], sub_token[sub_idx]);
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
			printf("t : %p, dir : %p\n", temp, dirp->d_name);
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
	if (!change_token)
	{
		free(*sub_token);
		sub_token = &change_token;
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
		ret join all sub_token
	*/
	return ("ok");
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
	printf("\nresult :\n\n%s\n\n", asterisk_str);
	//free(asterisk_str);
	//system("leaks a.out");
}