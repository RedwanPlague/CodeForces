#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
 
int main()
{
   int n, hmax, k;
   cin>>n>>hmax>>k;
   int a[n+1], h=0, i, j;
   ll tm=0;
   for(i=0; i<n; i++) cin>>a[i];
   a[n]=1000000001;
   i=0; 
   while(i<n || h>0) {
       while(h+a[i]<=hmax) h+=a[i++];
       tm+=h/k;
       h%=k;
       if(h+a[i]>hmax && h>0) {
           h=0; tm++;
       }
   }
   cout<<tm<<endl;
   return 0;
}