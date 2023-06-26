#include <stdio.h>
int main()
{
    int i, N, a[14]={4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    scanf("%d", &N);
    for(i=0; i<14; i++)
        if(N%a[i]==0)
            break;
    if(i<14)
        printf("YES");
    else
        printf("NO");
    return 0;
}