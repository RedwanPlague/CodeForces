#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define loop(n) for(i=0; i<n; i++)
 
int main()
{
   int n;
   cin>>n;
   int r=sqrt(n);
   for(; n%r!=0; r--) {}
   printf("%d %d\n", r, n/r);
   return 0;
}