#include <stdio.h>
#include <string.h>
int main()
{
    int i, la, lb;
    char a[101], b[101];
    scanf("%s", &a);
    scanf("%s", &b);
    la=strlen(a);
    lb=strlen(b);
    if(la!=lb)
        printf("NO\n");
    else {
    for(i=0; i<la; i++) {
        if(a[i]!=b[la-i-1])
            break;
    }
    if(i<la)
        printf("NO\n");
    else
        printf("YES\n");
    }
    return 0;
}