#include <stdio.h>
#include <stdlib.h>

int SetValue(char *str,int count)
{
	int i=0;
	for (i=0;i<count-1;++i)
	{
		str[i] = rand()%200;
	}
	str[i] = '\0';
	return 0;
}


int main(int argc, char *argv[])
{
	char *s1 = NULL;
	char *s2 = NULL;
	
	s1 = (char *)malloc(10000000);
	s2 = (char *)malloc(10000000);
	
	srand(time(NULL));
	SetValue(s1,10000000);
	SetValue(s2,10000000);

	//printf("s1 = %s\n",s1);
	//printf("s2 = %s\n",s2);

	exit(0);
}

