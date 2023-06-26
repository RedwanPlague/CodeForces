#include <stdio.h>
#include <math.h>
int main()
{
    int n, moves=0, m;
    char from[1001], to[1001];
    scanf("%d", &n);
    scanf("%s", from);
    scanf("%s", to);
    for(int i=0; i<n; i++) {
        m=abs(to[i]-from[i]);
        moves+= (m<10-m)?m:10-m;
    }
    printf("%d", moves);
    return 0;
}