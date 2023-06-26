#include <stdio.h>
#include <string.h>
 
int main()
{
   int i, l, c=0;
   char s[20];
   scanf("%s", s);
   l = strlen(s);
   for(i=0; i<l/2; i++) {
      if(s[i]!=s[l-1-i])
         c++;
   }
   if(l%2 && c<=1)
      printf("YES\n");
   else if(l%2==0 && c==1)
      printf("YES\n");
   else
      printf("NO\n");
   return 0;
}