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
   int n, i, t, l=1;
   cin>>n>>t;
   if(t<10) {
   if(n>1) printf("%d", t);
   for(i=l; i<n-l; i++) {
       printf("0");
   }
   printf("%d\n", t);
   }
   else {
       if(n==1) {
          printf("-1\n");
          return 0;
       }
       printf("1");
       for(i=1; i<n; i++) printf("0");
       putchar('\n');
   }
   return 0;
}