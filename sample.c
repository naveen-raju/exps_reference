#include <time.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	time_t t1, t2;
	t1 = time(NULL);
	sleep(10);
	t2 = time(NULL);
	printf("%lf", (double) difftime(t2, t1));
}
