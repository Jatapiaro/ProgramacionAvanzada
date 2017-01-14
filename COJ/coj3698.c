#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,mayus,minus,i;
	char str[11];


	scanf("%d %s",&n,str);
	str[n] = '\0';

	i = 0;
	mayus = 0;
	minus = 0;
	while(str[i]!='\0'){
		if(str[i]>='a' && str[i]<='z'){
			minus++;
		}else{
			mayus++;
		}
		i++;
	}
	printf("%d %d\n", mayus, minus);
}