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
   int *L = new int[n];
   int *chop = new int[n];
 
   for(int i=0; i<n; i++)
   {
      cin>>L[i];
   }
 
   int ans = 0;
   memset(chop, 0, n*sizeof(chop));
 
   for(int i=n-1; i>=0; i--)
   {
      if(i+1 < n)
         chop[i] += chop[i+1];
      if(i-1 >= 0)
         chop[i-1]++;
      if(i-L[i]-1 >= 0)
         chop[i-L[i]-1]--;
      if(chop[i] <= 0)
         ans++;
   }
 
   cout<<ans<<endl;
 
   delete[] L;
   delete[] chop;
 
   return 0;
}
 