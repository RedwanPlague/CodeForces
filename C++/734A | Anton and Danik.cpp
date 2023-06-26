#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
 
int main()
{
   int n, a=0, d=0;
   char c;
   cin>>n;
   getchar();
   for(int i=0; i<n; i++) {
       c=getchar();
       if(c=='A') a++;
       else d++;
   }
   if(a>d) puts("Anton");
   else if(d>a) puts("Danik");
   else puts("Friendship");
   return 0;
}