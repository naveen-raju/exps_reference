#include <stdio.h>
#include <string.h>

#define SEPERATOR ","
int main(int argc, char *argv[])
{
   char *data;
   char *temp;
   int array[100];
   int i, n;
   if (argc < 2) {
      printf("Usage:<prog_name> <comma seperated list of numbers>\n");
      return 1;
   }
   data =strdup(argv[1]);
   temp = strtok(data, SEPERATOR);
   array[0] = atoi(temp);
   i = 1;
   while (temp)  {
      temp = strtok(NULL, SEPERATOR);
      if (temp) {
         array[i++] = atoi(temp);
      }
   }
   n = i -1;
   for (i = 0; i <= n;i++) {
      printf("value = %d\n", array[i]);
   }
   return 0;
}
