#include <iostream>
using namespace std;
 
#define MOD 1000000007
 
int main()
{
   int n;
   cin>>n;
   long long a = 1, b = 0, c = 0;
   for(int i=2; i<=n; i++)
   {
      c = ( (2*b)%MOD + (3*a)%MOD )%MOD;
      a = b;
      b = c;
   }
   cout<<c;
   return 0;
}