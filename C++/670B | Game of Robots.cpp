#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ll n, k;
   cin>>n>>k;
   int *ar = new int[n];
   for(ll i=0; i<n; i++)
      cin>>ar[i];
   ll lo = 0, hi = n-1, mid;
   while(lo<hi-1)
   {
      mid = (lo+hi)/2;
      if((mid*(mid+1))/2>k)
         hi = mid-1;
      else
         lo = mid;
   }
   if((hi*(hi+1))/2<=k)
   {
      if(k==(hi*(hi+1))/2)
         cout<<ar[hi-1]<<endl;
      else
         cout<<ar[k-(hi*(hi+1))/2-1]<<endl;
   }
   else
   {
      if(k==(lo*(lo+1))/2)
         cout<<ar[lo-1]<<endl;
      else
         cout<<ar[k-(lo*(lo+1))/2-1]<<endl;
   }
   delete ar;
   return 0;
}
 