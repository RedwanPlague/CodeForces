#include <stdio.h>
int main()
{
   int N, i;
   scanf("%d", &N);
   i=0;
   while(1)
   {
      putchar('a');
      i++;
      if(i==N)
         break;
      putchar('a');
      i++;
      if(i==N)
         break;
      putchar('b');
      i++;
      if(i==N)
         break;
      putchar('b');
      i++;
      if(i==N)
         break;
   }
   return 0;
}