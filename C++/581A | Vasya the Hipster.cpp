#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
 
int main()
{
   int a, b;
   cin>>a>>b;
   cout<<min(a,b)<<' '<<((a+b)-2*min(a,b))/2<<endl;
   return 0;
}