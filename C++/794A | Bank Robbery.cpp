#include <stdio.h>
int main()
{
    int a, b, c, n, x, notes=0;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        if(x>b && x<c) notes++;
    }
    printf("%d", notes);
    return 0;
}