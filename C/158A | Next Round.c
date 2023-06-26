#include <stdio.h>
int main()
{
    int n, k, i, count=0;
    scanf("%d %d", &n, &k);
    int score[n];
    for(i=0; i<n; i++)
        scanf("%d", &score[i]);
    for(i=0; i<n; i++)
    {
        if(score[i]>=score[k-1] && score[i]>0)
            count++;
    }
    printf("%d\n", count);
    return 0;
}