#include <stdio.h>
#define M 1000005
int mark[M];
void make()
{
    int i, j;
    mark[1]=1;
    for(i=4; i<M; i+=2) mark[i]=1;
    for(i=3; i*i<M; i+=2) {
        if(!mark[i])
        for(j=i*i; j<M; j+=2*i)  mark[j]=1;
    }
}
int main()
{
    make();
    int n, i, c=1;
    scanf("%d", &n);
    if(n>2) c++;
    printf("%d\n", c);
    for(i=2; i<=n+1; i++) printf("%d ", mark[i]+1);
    return 0;
}