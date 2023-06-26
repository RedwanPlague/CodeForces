#include <stdio.h>
main()
{
    int N, i, j, d, n=0;
    scanf("%d", &N);
    int c[N];
    for(i=0; i<N; i++)
        c[i]=0;
    for(i=0; i<N; i++) {
        for(j=0; j<3; j++) {
            scanf("%d", &d);
            c[i]+=d;
        }
        if(c[i]>=2)
            n++;
    }
    printf("%d", n);
}