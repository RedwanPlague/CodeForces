#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
   int n;
   cin>>n;
   ll a[n+1], mx[n+1], com[n+1];
   for(int i=1; i<=n; i++)
   {
      cin>>a[i];
   }
   mx[1] = 1;
   for(int i=2; i<=n; i++)
   {
      mx[i] = max(mx[i-1], a[i]+1);
      //cout<<mx[i]<<' ';
   }
   //cout<<endl;
   com[n] = n - mx[n];
   for(int i=n-1; i>1; i--)
   {
      com[i] = min(com[i+1], i-mx[i]);
   }
   /*for(int i=2; i<=n; i++)
   {
      cout<<com[i]<<' ';
   }*/
   ll sum = 0;
   for(int i=2; i<=n; i++)
   {
      sum += (i-a[i]-com[i]-1);
   }
   cout<<sum<<endl;
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 