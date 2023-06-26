#include <stdio.h>
int main()
{
    int n, S=0, a;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        S+=a;
    }
    printf("%.12lf\n", (S+0.0)/n);
    return 0;
}