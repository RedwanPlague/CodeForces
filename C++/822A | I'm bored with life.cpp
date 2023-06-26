#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact(ll n)
{
   if(n==1) return 1;
   return n*fact(n-1);
}
int main()
{
   ll a, b;
   cin>>a>>b;
   cout<<fact(min(a,b))<<endl;
   return 0;
}