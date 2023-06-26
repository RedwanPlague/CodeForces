#include <stdio.h>
 
int turn(int t)
{
   if(t==24) return 0;
   return 10*(t%10)+t/10;
}
 
int main()
{
   int h, m, mins, times, ans, i;
   scanf("%d:%d", &h, &m);
   times=60*h+m;
   int a[]={0,1,2,3,4,5,10,11,12,13,14,15,20,21,22,23,24};
   for(i=0; i<17; i++) if(a[i]>=h) break;
   mins=a[i]*60+turn(a[i]);
   if(mins>=times) ans = mins-times;
   else {
      i++;
      mins=a[i]*60+turn(a[i]);
      ans = mins-times;
   }
   printf("%d\n", ans);
   return 0;
}