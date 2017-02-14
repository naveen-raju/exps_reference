#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MB 1024*1024

int main(int argc, char *argv[])
{
   void *myblock = NULL;
   long long count = 0;

   while (1)
   {
      myblock = (void *) malloc(100*MB);
      if (!myblock) {
         printf("malloc failed\n");
         break;
      }
      memset(myblock, 1, 100*MB);
      printf("Currently allocating %d MB\n", ++count*100);
   }

   exit(0);
}
