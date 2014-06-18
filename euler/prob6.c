#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

   if (argc < 2) {
      printf("Usage:<prog> <value>\n");
      return 1;
   }

   int n = atoi(argv[1]);
   unsigned long sq_of_sum = (n*(n+1))/2;
   sq_of_sum *= sq_of_sum;

   unsigned long sum_of_sq = (n*(n+1)*(2*n+1))/6;
   unsigned long val = sq_of_sum - sum_of_sq;
    
   printf (" n = %d, sum_of_square %lu square_of_sum %lu diff %lu\n", n, sum_of_sq,  sq_of_sum, val);
   return 0;
}

