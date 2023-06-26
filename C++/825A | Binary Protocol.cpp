#include <stdio.h>
int main()
{
   int value=0, l, i;
   char s[100];
   scanf("%d", &l);
   scanf("%s", s);
   for(i=0; i<l; i++)
   {
      if(s[i]=='0')
      {
         printf("%d", value);
         value = 0;
      }
      if(s[i]=='1')
         value++;
   }
   printf("%d\n", value);
   return 0;
}