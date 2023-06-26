#include <stdio.h>
int main()
{
    int a, x, y;
    scanf("%d %d %d", &a, &x, &y);
    if(y%a==0 || x>=a || x<=-a) {
        printf("-1");
        return 0;
    }
    y=y/a+1;
    if(y==1) {
        if(x<a/2.0 && x>-a/2.0) printf("1");
        else printf("-1");
        return 0;
    }
    if(y%2==0) {
        if(x<a/2.0 && x>-a/2.0) printf("%d", 3*y/2-1);
        else printf("-1");
        return 0;
    }
    if(x>0 && x<a) {
        printf("%d", (3*y-1)/2);
        return 0;
    }
    if(x<0 && x>-a) {
        printf("%d", 3*(y-1)/2);
        return 0;
    }
    printf("-1");
    return 0;
}