#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *str = calloc(3,1);
	str[2] = '\0';
	str[1] = 'c';
	str[0] = '1';
	str++;
	printf("%c", *(str -1));
	printf("%c", str[-1]);
	
}

