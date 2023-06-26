#include <stdio.h>
#include <string.h>
int main()
{
    int l,i,N;
    scanf("%d", &N);
    char a[100];
    for(i=0; i<N; i++)
    {
        scanf("%s", &a);
        l=strlen(a);
        if(l<=10)
        printf("%s\n", a);
        else
        printf("%c%d%c\n", a[0], l-2, a[l-1]);
    }
    return 0;
}