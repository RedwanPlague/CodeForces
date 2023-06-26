#include <stdio.h>
 
int main()
{
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) {
        if(i%2==0) for(j=0; j<m; j++) putchar('#');
        else if(i%4==1) {
            for(j=1; j<m; j++) putchar('.');
            putchar('#');
        }
        else {
            putchar('#');
            for(j=1; j<m; j++) putchar('.');
        }
        putchar('\n');
    }
    return 0;
}