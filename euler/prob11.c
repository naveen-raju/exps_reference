#include<stdio.h>

int main()
{
   int grid[20][20], i, j;
   FILE *input;
   input = fopen("input.dat", "r");
   if (!input) {
      printf("input file open error\n");
      return 1;
   }
   int n = 20;
   for (i = 0; i < n ; i++)
      for (j = 0; j < n; j++)
         fscanf(input, "%d", &grid[i][j]);

   //grid data
   for (i = 0; i < n ; i++) {
      printf("\n");
      for (j = 0; j < n; j++)
         printf("%d ", grid[i][j]);
   }
   
   int value = 0
   for (i = 0; i+1 < n; i++) {
      for (j =0; j+1 < n; j++) {
         temp = grid[i][j] * grid[i][j+1] * grid[i+1][j] * grid[i+1][j+1];
         if (temp > val) val = temp;
      }
   }

   print("Largest 
   return 0;
}
