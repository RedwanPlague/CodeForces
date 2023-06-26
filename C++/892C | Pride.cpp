#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 107
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n;
   cin>>n;
   int *a = new int[n];
 
   int cnt1 = 0;
 
   for(int i=0; i<n; i++)
   {
      cin>>a[i];
      if(a[i] == 1)
         cnt1++;
   }
 
   if(cnt1)
   {
      cout<<n-cnt1<<endl;
      return 0;
   }
 
   int minSeg = 5000;
   bool found = false;
 
   for(int i=0; i<n-1; i++)
   {
      int seg = 1, gcd = a[i];
      for(int j=i+1; j<n; j++)
      {
         gcd = __gcd(gcd, a[j]);
         //cout<<gcd<<' ';
         seg++;
         //cout<<seg<<endl;
         if(gcd == 1)
         {
            found = true;
            break;
         }
      }
      if(gcd == 1)
         minSeg = min(minSeg, seg);
   }
 
   if(!found)
      cout<<-1<<endl;
   else
      cout<<minSeg+n-2<<endl;
 
   return 0;
}
 