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