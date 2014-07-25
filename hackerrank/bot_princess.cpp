#include <iostream>

using namespace std;

int main()
{
   int n, grid[100][100];
   int pos[2][2], dist;
   char ch;
   cin >> n;
   for (int i = 0; i < n ; i++){ 
      for (int j = 0; j < n ; j++) {
         ch = getchar();
         if (ch == '\n') {
            j--;
         } else if (ch == 'm') {
            pos[0][0] = i;
            pos[0][1] = j;
         } else if (ch == 'p') {
            pos[1][0] = i;
            pos[1][1] = j;
         }
      }
   }

   if (pos[0][0] < pos[1][0]) {
      dist = pos[1][0] - pos[0][0];
      while (dist > 0) {
         cout << "DOWN\n";
         dist--;
      }
   } else if (pos[0][0] > pos[1][0]) {
      dist = pos[1][0] - pos[0][0];
      while (dist) {
         cout << "UP\n";
         dist--;
      }
   }

   //perform left or right movement
   if (pos[0][1] < pos[1][1]) {
      dist = pos[1][1] - pos[0][1];
      while (dist > 0) {
         cout << "LEFT\n";
         dist--;
      }

   } else if (pos[0][1] > pos[1][1]) {
      dist = pos[0][1] - pos[1][1];
      while (dist) {
         cout << "RIGHT\n";
         dist--;
      }
   }

   return 0;
}
