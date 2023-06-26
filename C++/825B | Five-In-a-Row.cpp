#include <stdio.h>
 
int main()
{
   char gr[15][15];
   int i, j, l, f=0;
   for(i=0; i<10; i++)
   {
      for(j=0; j<10; j++)
         scanf("%c", &gr[i][j]);
      getchar();
   }
   for(i=0; i<10; i++)
   {
      for(j=0; j<6; j++)
         if( (gr[i][j]+gr[i][j+1]+gr[i][j+2]+gr[i][j+3]+gr[i][j+4]) == 398 ) f = 1;
   }
   for(j=0; j<10; j++)
   {
      for(i=0; i<6; i++)
         if( (gr[i][j]+gr[i+1][j]+gr[i+2][j]+gr[i+3][j]+gr[i+4][j]) == 398 ) f = 1;
   }
   for(i=0; i<6; i++)
   {
      for(j=0; j<6; j++)
         if( (gr[i][j]+gr[i+1][j+1]+gr[i+2][j+2]+gr[i+3][j+3]+gr[i+4][j+4]) == 398 ) f = 1;
   }
   for(i=4; i<10; i++)
   {
      for(j=0; j<6; j++)
         if( (gr[i][j]+gr[i-1][j+1]+gr[i-2][j+2]+gr[i-3][j+3]+gr[i-4][j+4]) == 398 ) f = 1;
   }
   if( !f )
      puts("NO");
   else
      puts("YES");
   return 0;
}