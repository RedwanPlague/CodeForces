#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
ll a[100001];
ll dp[100001];
ll func(ll i)
{
    if(i==0) return 0; //or a[0]
    if(i==1) return a[1];
    if(dp[i]!=-1) return dp[i];
    dp[i]=max(func(i-1),func(i-2)+i*a[i]);
    return dp[i];
}
int main()
{
   ll i, n, elm;
   cin>>n;
   for(i=0; i<n; i++) {
       cin>>elm;
       a[elm]++;
   }
   memset(dp,-1,sizeof(dp));
   cout<<func(100000)<<endl;
   return 0;
}