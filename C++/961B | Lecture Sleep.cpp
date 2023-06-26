#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 107
 
int main()
{
   ios_base::sync_with_stdio(0);
 
   int n, k, t;
   cin>>n>>k;
   ll a[n+1], sleep[n+1];
   ll total = 0;
 
   for(int i=1; i<=n; i++)
   {
      cin>>a[i];
   }
 
   sleep[0] = 0;
 
   for(int i=1; i<=n; i++)
   {
      cin>>t;
      sleep[i] = sleep[i-1];
      if(t == 1)
      {
         total += a[i];
      }
      else
         sleep[i] += a[i];
      //cout<<sleep[i]<<' ';
   }
   //cout<<endl;
 
   ll maxLec = 0;
 
   for(int i=1; i+k-1<=n; i++)
   {
      maxLec = max(maxLec, sleep[i+k-1] - sleep[i-1]);
   }
 
   cout<<total+maxLec<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 