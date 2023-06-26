#include <stdio.h>
int main()
{
   int x1, x2, y1, y2, x, y;
   scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
   scanf("%d %d", &x, &y);
   if((x2-x1)%x==0 && (y2-y1)%y==0 && ((x2-x1)/x-(y2-y1)/y)%2==0) puts("YES");
   else puts("NO");
   return 0;
}