#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ll n, i, num=0, ans;
   cin>>n;
   ll a[n];
   for(i=0; i<n; i++) scanf("%lld", &a[i]);
   sort(a,a+n);
   if(a[0]==a[1] && a[1]==a[2]) {
      for(i=0; i<n && a[i]==a[0]; i++) num++;
      ans = num*(num-1)*(num-2)/6;
   }
   else if(a[0]==a[1]) {
      for(i=2; i<n && a[i]==a[2]; i++) num++;
      ans = num;
   }
   else if(a[1]==a[2]) {
      for(i=1; i<n && a[i]==a[1]; i++) num++;
      ans = num*(num-1)/2;
   }
   else {
      for(i=2; i<n && a[i]==a[2]; i++) num++;
      ans = num;
   }
   cout<<ans<<endl;
   return 0;
}