#include <stdio.h>
#include <sys/stat.h>

int main()
{
   printf("sizes \n int : %u", sizeof(int));
   printf("\n long : %u", sizeof(long));
   printf("\n double : %u", sizeof(double));
   printf("\n float : %u", sizeof(float));
   printf("\n long double : %u", sizeof(long double));
   printf("\n char : %u", sizeof(char));
   return 0;
}

