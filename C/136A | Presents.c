#include <stdio.h>
int main()
{
    int N, i;
    scanf("%d", &N);
    int a, b[N];
    for(i=0; i<N; i++) {
        scanf("%d", &a);
        b[a-1]=i+1;
    }
    for(i=0; i<N; i++)
        printf("%d ", b[i]);
    return 0;
}