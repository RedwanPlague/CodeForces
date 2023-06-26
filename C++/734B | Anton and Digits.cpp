#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
#define min3(a,b,c) min(a,min(b,c))
 
int main()
{
   ll k2, k3, k5, k6, S=0;
   cin>>k2>>k3>>k5>>k6;
   S+=256*min3(k2,k5,k6);
   k2-=min3(k2,k5,k6);
   S+=32*min(k2,k3);
   cout<<S<<endl;
   return 0;
}