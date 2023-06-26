#include <stdio.h>
#include <string.h>
 
int main()
{
   int i, l;
   char x[101], y[101], z[101];
   z[0] = '\0';
   scanf("%s", x);
   scanf("%s", y);
   l = strlen(x);
   for(i=0; i<l; i++) {
      if(x[i]>=y[i])
         z[i] = y[i];
      else if(x[i]<y[i])
         break;
   }
   z[l] = '\0';
   if(i<l)
      printf("-1\n");
   else
      printf("%s\n", z);
   return 0;
}