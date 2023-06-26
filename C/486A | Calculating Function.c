#include <stdio.h>
int main()
{
    long long A;
    scanf("%I64d", &A);
    if(A%2==0)
        printf("%I64d\n", A/2);
    else
        printf("%I64d\n", -(A+1)/2);
    return 0;
}