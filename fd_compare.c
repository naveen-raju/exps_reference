#include <stdio.h>
#include <stdlib.h>

int main() 
{
   FILE *fp;
   fp = stderr;
   if (fp == stderr) {
      fprintf(stdout, "comparison is possible\n");
      return 0;
   }
   exit(0);
}
