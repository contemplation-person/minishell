#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

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
		//printf("ino : %d\n", dirp->d_ino);
		printf("d_name : %s\n", dirp->d_name);
		//printf("d_name_len : %d\n", dirp->d_namlen);
		//printf("%d\n", dirp->d_reclen);
		printf("number : %d\n", dirp->d_seekoff);
		dirp = readdir(dp);
	}
	closedir(dp);
	//char *env = getenv("HOME");
	//printf("this : %s\n", env);
	//write(1,"---------------\n", strlen("---------------\n"));

	//if(chdir("~"))
	//{
	//	printf("error\n");
	//	return 0;
	//}
	//dp = opendir(".");
	//if (dp == NULL)
	//{
	//	printf("NULL");
	//	return 0;
	//}
	//dirp = readdir(dp);
	//if (dirp == NULL)
	//{
	//	printf("NULL");
	//	return 0;
	//}
	//while (dirp)
	//{
	//	printf("ino : %d\n", dirp->d_ino);
	//	printf("d_name : %s\n", dirp->d_name);
	//	printf("d_name_len : %d\n", dirp->d_namlen);
	//	//printf("%d\n", dirp->d_reclen);
	//	//printf("%d\n", dirp->d_seekoff);
	//	dirp = readdir(dp);
	//}
	//closedir(dp);

}

/*
int match(char *pattern, char *name)
{
	int	px;
	int	nx;
	int	total_p_len;
	int total_n_len;
	char c;

	px = 0;
	pn = 0;
	total_p_len = ft_strlen(pattern);
	total_n_len = ft_strlen(name);
	while (px < total_p_len || pn < total_n_len)
	{
		if (px < total_p_len)
		{
			c = patten[px];
			if (c == '*')
			{
				if (nx < total_n_len)
				{
					px++;
					nx++;
					cntinue ;
				}
			}
			else if (nx < total_n_len && name[nx] == c)
			{
				px++;
				nx++;
				continue ;
			}
			else
				return (0);
		}
	}
	return (1);
}

func match(pattern, name string) bool {
	px := 0
	nx := 0
	for px < len(pattern) || nx < len(name) 
	{
		if px < len(pattern) 
		{
			c := pattern[px]
			switch c 
			{
			default: // ordinary character
				if nx < len(name) && name[nx] == c {
					px++
					nx++
					continue
				}
			case '?': // single-character wildcard
				if nx < len(name) {
					px++
					nx++
					continue
				}
			case '*': // zero-or-more-character wildcard
				...
			}
		}
		// Mismatch.
		return false
	}
	// Matched all of pattern to all of name. Success.
	return true
}
*/