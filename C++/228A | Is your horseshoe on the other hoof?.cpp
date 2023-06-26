#include <stdio.h>
 
int main()
{
    int a[4], i, j, buy=4;
    for(i=0; i<4; i++) {
        scanf("%d", &a[i]);
        for(j=0; j<i; j++) if(a[i]==a[j]) break;
        if(j==i) buy--;
    }
    printf("%d", buy);
    return 0;
}