#include <cstdio>
 
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, a;
        scanf("%d", &n);
        int sum = 0, moves = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a);
            if(!a)
            {
                moves++;
                a = 1;
            }
            sum += a;
        }
        if(!sum)
            moves++;
        printf("%d\n", moves);
    }
 
    return 0;
}