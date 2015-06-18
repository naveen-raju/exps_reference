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
   
   RCD_DATA *data;
   int i;

   printf("Inside library\n");

   printf("number of mappings %d\n", bd->len);
   
   data = (RCD_DATA *)bd->data;
   
  
   for (i = 0; i < bd->len ; i++) {
      printf("%s", data[i].srcdata);
      printf("%s", data[i].tgtdata);
   }
}
