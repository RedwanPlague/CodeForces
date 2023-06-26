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
   int v0, v1, c, l, a, day=0;
   cin>>c>>v0>>v1>>a>>l;
   while(c>0) {
      c-=v0;
      v0+=a;
      if(v0>v1) v0=v1;
      if(c>0) c+=l;
      day++;
   }
   cout<<day<<endl;
   return 0;
}