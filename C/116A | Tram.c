#include <stdio.h>
int main()
{
    int i, N, a, b, S=0, max=0;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%d %d", &a, &b);
        S=S-a+b;
        if(max<S)
            max=S;
    }
    printf("%d", max);
    return 0;
}