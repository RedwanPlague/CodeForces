#include <iostream>
 
using namespace std;
 
int main()
{
   int b[5] = { 0 }, N, i, t;
   cin >> N;
   for(i=0; i<N; i++) {
      cin >> t;
      b[t]++;
   }
   b[1] = max(b[1]-b[3],0);
   t = b[3]+b[4]+(b[1]+2*b[2])/4;
   if( (b[1]+2*b[2])%4 != 0)
      t++;
   cout << t;
   return 0;
}