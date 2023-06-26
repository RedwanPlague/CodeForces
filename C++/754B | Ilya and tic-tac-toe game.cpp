#include <stdio.h>
 
int win(char a, char b, char c)
{
   if((a+b+c)=='x'+'x'+'.') return 1;
   return 0;
}
 
int main()
{
   int i, j;
   char a[4][4];
   for(i=0; i<4; i++) {
      for(j=0; j<4; j++) a[i][j]=getchar();
      getchar();
   }
   for(i=0; i<4; i++) {
      if(win(a[i][0],a[i][1],a[i][2])) {
         puts("YES");
         return 0;
      }
      if(win(a[i][3],a[i][1],a[i][2])) {
         puts("YES");
         return 0;
      }
   }
   for(i=0; i<4; i++) {
      if(win(a[0][i],a[1][i],a[2][i])) {
         puts("YES");
         return 0;
      }
      if(win(a[3][i],a[1][i],a[2][i])) {
         puts("YES");
         return 0;
      }
   }
   if(win(a[0][1],a[1][2],a[2][3])) {
      puts("YES");
      return 0;
   }
   if(win(a[1][0],a[2][1],a[3][2])) {
      puts("YES");
      return 0;
   }
   if(win(a[0][0],a[1][1],a[2][2])) {
      puts("YES");
      return 0;
   }
   if(win(a[1][1],a[2][2],a[3][3])) {
      puts("YES");
      return 0;
   }
   if(win(a[0][2],a[1][1],a[2][0])) {
      puts("YES");
      return 0;
   }
   if(win(a[1][3],a[2][2],a[3][1])) {
      puts("YES");
      return 0;
   }
   if(win(a[0][3],a[1][2],a[2][1])) {
      puts("YES");
      return 0;
   }
   if(win(a[1][2],a[2][1],a[3][0])) {
      puts("YES");
      return 0;
   }
   puts("NO");
   return 0;
}