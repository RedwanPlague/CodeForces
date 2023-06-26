#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char a[11], b[11], c[11];
    scanf("%s %s", a, b);
    scanf("%d", &n);
    printf("%s %s\n", a, b);
    while(n--) {
        scanf("%s", c);
        if(!strcmp(a,c)) scanf("%s", a);
        else scanf("%s", b);
        printf("%s %s\n", a, b);
    }
    return 0;
}