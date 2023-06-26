#include <stdio.h>
int main()
{
    int N, i, a, b, c, A=0, B=0, C=0;
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        A+=a;
        B+=b;
        C+=c;
    }
    if(A==0 && B==0 && C==0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}