#include <stdio.h>
 
int main()
{
 int l;
 scanf("%d", &l);
 char s[102];
 scanf("%s", s);
 int cnt = 0;
 for(int i=0; i+2<l; i++)
 {
     if(s[i] == 'x' && s[i+1] == 'x' && s[i+2] == 'x')
         cnt++;
 }
 printf("%d\n", cnt);
 return 0;
}