#include <stdio.h>

typedef struct _big_data {
   int len;
   void *data;
} BigData;

typedef struct _rcd_data {
   char srcdata[256];
   char tgtdata[256];
} RCD_DATA;

void print_data(BigData *bd) 
{
   
   int i;
   RCD_DATA *data;

   printf("Inside library\n");

   printf("number of mappings %d\n", bd->len);
   
   data = (RCD_DATA *)bd->data;
  
   for (i = 0; i < bd->len ; i++) {
      printf("%s\t", data[i].srcdata);
      printf("%s", data[i].tgtdata);
      printf("\n");
   }
   printf("\nEnd of Library call\n");
}
