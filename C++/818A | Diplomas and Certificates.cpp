#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
 
int main()
{
   ll n, k, d;
   cin>>n>>k;
   d = n/(2*(k+1));
   printf("%lld %lld %lld\n", d, k*d, n-d*(k+1));
   return 0;
}