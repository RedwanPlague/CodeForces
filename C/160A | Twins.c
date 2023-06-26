#include <stdio.h>
int main()
{
    int i, j, x, N, S=0, M=0;
    scanf("%d", &N);
    int a[N];
    for(i=0; i<N; i++) {
        scanf("%d", &a[i]);
        S+=a[i];
    }
    for(i=0; i<(N-1); i++)
        for(j=i+1; j<N; j++)
            if(a[i]<a[j]) {
                x=a[i];
                a[i]=a[j];
                a[j]=x;
            }
    for(i=0; i<N; i++) {
        M+=a[i];
        if( (2*M) > S )
            break;
    }
    printf("%d", i+1);
    return 0;
}