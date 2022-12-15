#include <unistd.h>
/*
	절대경로
	상대경로
	.
	..

*/
#include <stdio.h>
int main()
{
	int a = chdir("/bin");
	printf("%s",getcwd(NULL, 100000000));
	printf("%d\n", a);
	return (0);
}