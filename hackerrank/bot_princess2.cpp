#include <iostream>
#include <vector>
#include <string>

using namespace std;

void nextMove(int n, int r, int c, vector <string> grid)
{
   int p = -1;
   int count = -1;
   for (vector <string>::iterator it = grid.begin(); it != grid.end(); it++) {
      count++;
      p = (*it).find_first_of('p');
      if (p >= 0) {
      //   cout << "position of the p " << count << "," << p;
         break;
      }
   }


   if (count == r) {
      if (r > p) cout << "LEFT";
      else cout << "RIGHT";
   } else if (p == c) {
      if (count > c) cout << "UP";
      else cout << "DOWN";
   } else {
      if (r < count) cout << "DOWN";
      else cout << "UP";
   }

   cout << "\n";
}

int main(void) {

   int n, r, c, i;
   vector <string> grid;

   cin >> n;
   cin >> r;
   cin >> c;

   for(i=0; i<n; i++) {
      string s; cin >> s;
      grid.push_back(s);
   }

   nextMove(n, r, c, grid);
   return 0;
}
