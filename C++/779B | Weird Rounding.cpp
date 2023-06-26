#include <stdio.h>
#include <string.h>
int main()
{
   int n, i, l, del=0, zero=0;
   char s[10];
   scanf("%s %d", s, &n);
   l=strlen(s);
   strrev(s);
   if(l<=n) {
      del=l;
      for(i=0; i<l; i++)
      if(s[i]=='0') del=l-1;
   }
   else {
   for(i=0; i<l; i++) {
      if(s[i]=='0') zero++;
      else del++;
      if(zero==n) break;
   }
      if(i==l && zero<n) del=l-1;
   }
   printf("%d", del);
   return 0;
}