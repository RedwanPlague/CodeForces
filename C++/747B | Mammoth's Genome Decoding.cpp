#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define LOOP(l) for(i=0; i<l; i++)
 
int main()
{
   int l, i, j, a[4];
   char b[4]={'A','T','C','G'};
   char s[256];
   cin>>l;
   scanf("%s", s);
   if(l%4!=0) {
      puts("===");
      return 0;
   }
   LOOP(4) a[i]=l/4;
   LOOP(l) {
      if(s[i]=='A') a[0]--;
      else if(s[i]=='T') a[1]--;
      else if(s[i]=='C') a[2]--;
      else if(s[i]=='G') a[3]--;
   }
   LOOP(4) if(a[i]<0) {
      puts("===");
      return 0;
   }
   LOOP(l) {
      if(s[i]=='?') {
         for(j=0; j<4; j++) {
            if(a[j]>0) {
            s[i]=b[j];
            a[j]--;
            break;
         } }
      }
   }
   puts(s);
   return 0;
}