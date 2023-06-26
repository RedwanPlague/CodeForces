#include <stdio.h>
int main()
{
    int i, N, f, max=0;
    scanf("%d", &N);
    int a[N];
    for(i=0; i<N; i++)
        scanf("%d", &a[i]);
    f=1;
    for(i=0; i<(N-1); i++) {
        if(a[i]<=a[i+1])
            f++;
        else
        {
            if(max<f)
                max=f;
            f=1;
        }
    }
    if(max<f)
        max=f;
    printf("%d\n", max);
    return 0;
}