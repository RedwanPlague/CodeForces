#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
   int N;
   cin>>N;
   ll a[200005];
   ll sum = 0;
   ll cur = 0;
   for(int i=0; i<N; i++)
   {
      cin>>a[i];
      sum += a[i];
   }
   for(int i=0; i<N; i++)
   {
      cur += a[i];
      if(2*cur >= sum)
      {
         cout<<i+1<<endl;
         return 0;
      }
   }
   return 0;
}