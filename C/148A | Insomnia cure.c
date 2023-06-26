#include <stdio.h>
int main()
{
    int i, a[4], d, S=0;
    for(i=0; i<4; i++)
        scanf("%d", &a[i]);
    scanf("%d", &d);
    for(i=1; i<=d; i++)
        if( !(i%a[0] && i%a[1] && i%a[2] && i%a[3]))
            S++;
    printf("%d\n", S);
    return 0;
}