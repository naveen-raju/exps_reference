#include <stdio.h>
#include <string.h>

char *return_str_literal()
{
   char *name;
   name = "String literal test...\n";
   return name;
}

int main()
{
   printf("value assigned after declaration for string literal : %s\n", return_str_literal());
   return 0;
}
