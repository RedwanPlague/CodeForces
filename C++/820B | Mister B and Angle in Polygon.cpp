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
   double a;
   cin>>n>>a;
   double ang=180.0/n;
   int diff1 = a/ang;
   double ans1=ang*(diff1+0.0);
   int diff2 = ceil(a/ang);
   double ans2=ang*(diff2+0.0);
   int diff;
   if((a-ans1)<(ans2-a) && diff1!=0) diff = diff1;
   else diff = diff2;
   if(diff>(n-2)) diff=n-2;
   //printf("%d %d %d %lf %lf %lf\n", diff1, diff2, diff, a-ans1, ans2-a, ang);
   printf("%d %d %d\n", 1, n, diff+1);
   return 0;
}