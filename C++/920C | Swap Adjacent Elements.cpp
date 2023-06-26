#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
   int n;
   string swp;
   cin>>n;
   int ar[n+1], left[n+1], right[n+1];
 
   for(int i=1; i<=n; i++)
      cin>>ar[i];
 
   cin>>swp;
 
   left[1] = 0;
   for(int i=0, j=2; i<swp.length(); i++, j++)
   {
      left[j] = left[j-1];
      if(swp[i] == '0')
         left[j] = i+1;
   }
 
   right[n] = n;
   for(int i=swp.length()-1, j=n-1; i>=0; i--, j--)
   {
      right[j] = right[j+1];
      if(swp[i] == '0')
         right[j] = j;
   }
 
   for(int i=1; i<=n; i++)
   {
      if(ar[i] <= left[i] || ar[i] > right[i])
      {
         cout<<"NO"<<endl;
         return 0;
      }
   }
   cout<<"YES"<<endl;
 
   return 0;
}
 