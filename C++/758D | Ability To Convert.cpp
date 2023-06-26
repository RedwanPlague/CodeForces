#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
 
ll pow(ll x, ll n)
{
   if(n==0) return 1;
   ll a=pow(x,n/2);
   a=a*a;
   if(n%2) a=x*a;
   return a;
}
 
ll sze(ll n)
{
   ll i=0;
   while(n>0) {
      n/=10;
      i++;
   }
   return i;
}
 
ll trans(char *p, char *q)
{
   ll a=0;
   ll i;
   for(i=0; p>=q; p--,i++) a+=(*p-'0')*pow(10,i);
   return a;
}
 
int main()
{
   ll n, x=0, b;
   char s[61];
   scanf("%lld", &n); getchar();
   scanf("%s", s);
   ll sz=sze(n);
   ll l=strlen(s);
   ll i=l-1, j, p=0;
   while(i>=0) {
      j=i-sz+1;
      if(j<0) j=0;
      b=trans(s+i,s+j);
      if(b>=n) j++;
      while(s[j]=='0' && j<i) j++;
      b=trans(s+i,s+j);
      i=j-1;
      x+=b*pow(n,p++);
   }
   printf("%lld", x);
   return 0;
}