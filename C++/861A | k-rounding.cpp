#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int manys(ll n, ll div)
{
   int many = 0;
   while(n%div==0)
   {
      n/=div;
      many++;
   }
   return many;
}
int main()
{
 ll n, i;
 int k;
 cin>>n>>k;
 n *= (pow(5,max(0,k-manys(n,5)))*pow(2,max(0,k-manys(n,2))));
   cout<<n<<endl;
 return 0;
}