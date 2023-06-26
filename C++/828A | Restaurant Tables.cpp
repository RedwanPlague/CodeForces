#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
 int n, os, ts, ots=0, g, dg=0;
 cin>>n>>os>>ts;
 while(n--) {
      cin>>g;
      if(g==1) {
         if(os>0)
            os--;
         else if(ts>0) {
            ts--;
            ots++;
         }
         else if(ots>0)
            ots--;
         else
            dg++;
      }
      else {
         if(ts>0)
            ts--;
         else
            dg+=2;
      }
 }
 cout<<dg<<endl;
 return 0;
}