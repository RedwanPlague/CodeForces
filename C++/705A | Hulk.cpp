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
   int n, i;
   cin>>n;
   for(i=0; i<n; i++) {
       if(i>0) printf("that ");
       if(i%2==0) printf("I hate ");
       else printf("I love ");
   }
   printf("it\n");
   return 0;
}
 