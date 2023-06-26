#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1000000007
 
int turn(char c)
{
   if(c>='0' && c<='9') return c-'0';
   if(c>='A' && c<='Z') return c-'A'+10;
   if(c>='a' && c<='z') return c-'a'+36;
   if(c=='-') return 62;
   return 63;
}
 
int main()
{
   char s[100001];
   int l, i, j;
   scanf("%s", s);
   l=strlen(s);
   int a[l];
   ll ways=1;
   for(i=0; i<l; i++) a[i]=turn(s[i]);
   for(i=0; i<l; i++) {
      for(j=0; j<6; j++) if((a[i]&(1<<j))==0) {
         ways=(3*ways)%MOD;
      }
   }
   cout<<ways<<endl;
   return 0;
}