#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int T;
   cin >> T;

   unsigned int i,j,k,p,q;
   unsigned int N, Q;

   unsigned short int array[100000];
   vector<int> array_of_1s[16], array_of_0s[16];

   for (i = 0; i < T; i++) {
      cin >> N >> Q;
      
      for (j = 0; j < N ; j++) {
         cin >> array[j];
         for (k = 0; k < 16;k++) {
            if (temp & (1<<k)) {
               array_of_1s[k].push_back(j);
            } else {
               array_of_0s[k].push_back(j);
            }
         }
      }

      for (k = 0; k < 16;k++) {
         sort(array_of_1s[k].begin(), array_of_1s[k].end());
         sort(array_of_0s[k].begin(), array_of_0s[k].end());
      }

      for (j = 0; j < Q; j++) {
         cin >> a >> p >> q;

         unsigned short max = 0, temp;
         for (k = p-1; k < q; k++) {
            temp = a ^ array[k];
            if (temp > max) max = temp;
         }
         cout << max << endl;
      }
   }
   return 0;
}
