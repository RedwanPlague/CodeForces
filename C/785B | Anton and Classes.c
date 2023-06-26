#include <stdio.h>
int main()
{
    int N, M, i, ml1=0, ml2=0, mr1=1000000002, mr2=1000000002;
    scanf("%d", &N);
    int l1[N], r1[N];
    for(i=0; i<N; i++) {
        scanf("%d %d", &l1[i], &r1[i]);
        if(ml1<l1[i])
            ml1=l1[i];
        if(mr1>r1[i])
            mr1=r1[i];
    }
    scanf("%d", &M);
    int l2[M], r2[M];
    for(i=0; i<M; i++) {
        scanf("%d %d", &l2[i], &r2[i]);
        if(ml2<l2[i])
            ml2=l2[i];
        if(mr2>r2[i])
            mr2=r2[i];
    }
    M=ml2-mr1;
    N=ml1-mr2;
    i=M;
    if(i<N)
        i=N;
    if(i<0)
        i=0;
    printf("%d", i);
    return 0;
}