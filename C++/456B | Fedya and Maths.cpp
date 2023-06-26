#include <stdio.h>
int main()
{
   char a, b, c;
   while(1) {
      if((a=getchar())=='\n') break;
      if((b=getchar())=='\n') break;
      if((c=getchar())=='\n') break;
   }
   if(a=='\n') a=10*(b-'0')+(c-'0');
   else if(b=='\n') a=10*(c-'0')+(a-'0');
   else if(c=='\n') a=10*(a-'0')+(b-'0');
   if(a%4) putchar('0');
   else putchar('4');
   return 0;
}