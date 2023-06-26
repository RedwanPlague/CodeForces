#include <stdio.h>
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int h, m;
        scanf("%d %d", &h, &m);
        if(!h && !m)
            printf("0\n");
        else 
            printf("%d\n", 1440-60*h-m);
    }
    return 0;
}