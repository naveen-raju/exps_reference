#include <stdio.h>

typedef struct sample {
   int id;
   char data[1];
   int sal;
} SAMPLE;

int main()
{
   printf("Size of struct %d", sizeof(SAMPLE));
   return 0;
}
