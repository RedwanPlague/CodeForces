#include <stdio.h>
#include <string.h>
 
int main()
{
   int i, l, c=0;
   char s[101];
   scanf("%s", s);
   l = strlen(s);
   for(i=0; i<(l-1); i++) {
      if(s[i]=='V' && s[i+1]=='K') {
         s[i] = '\0';
         s[i+1] = '\0';
         c++;
      }
   }
   for(i=0; i<(l-1); i++) {
      if(s[i]=='V' && s[i+1]=='V') {
         c++;
         break;
      }
      else if(s[i]=='K' && s[i+1]=='K') {
         c++;
         break;
      }
   }
   printf("%d\n", c);
   return 0;
}