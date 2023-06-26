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
   int *b = new int[n];
   for(int i=0; i<n; i++)
   {
      cin>>a[i];
      b[i] = a[i];
   }
 
   sort(b, b+n);
 
   for(int i=0; i<n; i++)
   {
      if(a[i] == b[n-1])
         cout<<b[0]<<' ';
      else
         cout<<*upper_bound(b, b+n, a[i])<<' ';
   }
 
   return 0;
}