#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
 
int main()
{
   int n, i;
   cin>>n;
   int a[n], b[n], h[n];
   for(i=0; i<n; i++) cin>>a[i];
   b[n-1]=a[n-1];
   h[n-1]=0;
   for(i=n-2; i>=0; i--) {
      b[i]=max(b[i+1],a[i]);
      h[i]=b[i]-a[i];
      if(a[i]<=b[i+1]) h[i]++;
   }
   for(i=0; i<n; i++) cout<<h[i]<<' ';
   cout<<endl;
   return 0;
}