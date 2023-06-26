#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
 
int main()
{
   int n, h, a, W=0;
   cin>>n>>h;
   while(n--) {
       cin>>a;
       if(a>h) W+=2;
       else W++;
   }
   cout<<W<<endl;
   return 0;
}