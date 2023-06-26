#include <stdio.h>
#include <string.h>
 
int main()
{
    int N;
    scanf("%d", &N);
    int freq[1005], a[60];
    memset(freq, 0, sizeof(freq));
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }
    for(int i=0; i<N; i++)
    {
        freq[a[i]]--;
        if(freq[a[i]] != 0)
            a[i] = -1;
    }
    int cnt = 0;
    for(int i=0; i<N; i++)
    {
        if(a[i] != -1)
            cnt++;
    }
    printf("%d\n", cnt);
    for(int i=0; i<N; i++)
    {
        if(a[i] != -1)
            printf("%d ", a[i]);
    }
    return 0;
}