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
   int n;
   int a, b, c;
   int x, y, z;
   cin>>n;
   cin>>a>>b>>c;
   int mx=0;
   for(x=0; x<=4000; x++) {
       for(y=0; y<=4000; y++) {
           if((n-x*a-y*b)%c!=0 || n<(a*x+y*b)) continue;
           z = (n-x*a-y*b)/c;
           if((x+y+z)>mx) mx = x+y+z;
       }
   }
   cout<<mx<<endl;
   return 0;
}