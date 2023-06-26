#include <stdio.h>
#include <math.h>
int main()
{
    int yr;
    scanf("%d", &yr);
    int m=pow(10,(int)log10(yr));
    m = ((yr/m)+1)*m;
    printf("%d", m-yr);
    return 0;
}