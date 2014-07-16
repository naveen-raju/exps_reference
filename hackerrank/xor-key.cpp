#include <iostream>
using namespace std;

int main()
{
   int T;
   cin >> T;

   unsigned int i,j,k,p,q;
   unsigned int N, Q;
   unsigned short int a;
   unsigned short int array[100000];
   for (i = 0; i < T; i++) {
      cin >> N >> Q;
      
      for (j = 0; j < N ; j++) {
         cin >> array[j];
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
