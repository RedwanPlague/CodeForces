#include <stdio.h>
int main()
{
    int n, t, k, d,m;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    m = n/k;
    if(n%k==0)
        m--;
    m = m*t;
    if(m>d)
     printf("YES");
    else
    printf("NO");
   return 0;
}