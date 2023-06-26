#include <stdio.h>
int main()
{
   int a[8][4];
   int i, j;
   for(i=0; i<4; i++) {
      for(j=0; j<4; j++) {
         scanf("%d", &a[i][j]);
         a[i+4][j]=a[i][j];
      }
   }
   int safe=1;
   for(i=0; i<4; i++) {
      if(a[i][3]==1) {
         for(j=0; j<3; j++) if(a[i][j]==1) safe=0;
         if(a[i+1][0]==1) safe=0;
         if(a[i+2][1]==1) safe=0;
         if(a[i+3][2]==1) safe=0;
      }
   }
   if(safe==1) printf("NO");
   else printf("YES");
   return 0;
}