#include<stdio.h>
#include<ctype.h>

int main()
{
	char *naveen;
	unsigned long y = 2131;
	unsigned long  x;
	asprintf(&naveen, ".audit.%luxxxx", y);
	char *str = naveen;
	printf("%s", naveen);
	while(*str != '\0') {
		if (isdigit(*str)) {
			x = strtol(str, &str, 10);
		} else {
			str++;
		}
	}
	printf("Num = %lu", x);
	fflush(stdout);
}
