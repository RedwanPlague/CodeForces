#include <stdio.h>
int main()
{
    int i, N, p, q, room=0;
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%d %d", &p, &q);
        if( (q-p) >= 2)
            room++;
    }
    printf("%d", room);
    return 0;
}