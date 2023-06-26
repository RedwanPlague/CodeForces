#include <stdio.h>
#include <math.h>
int main()
{
    int n, h, i;
    double x;
    scanf("%d %d", &n, &h);
    x = h/sqrt(n);
    for(i=1; i<=(n-1); i++)
        printf("%.10lf ", x*sqrt(i));
    return 0;
}