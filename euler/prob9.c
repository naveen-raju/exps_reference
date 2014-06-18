#include <stdio.h>

int main()
{
   int x,y,z;
   for (x = 1; x < 1000; x++) {
      for (y = x+1; y < 1000; y++) {
         for (z = y+1; x+y+z <= 1000; z++) {
            if ((z*z) == ((x*x) + (y*y)) && ((x+y+z)== 1000)) {
               printf("the numbers are x=%d y=%d z=%d\n", x,y,z);
               printf("product %lu\n", (x*y*z)); 
               return 0;
            }
         }
      }
   }
}
