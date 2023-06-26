#include <stdio.h>
int main()
{
    int i, N, count=0;
    char s[51];
    scanf("%d", &N);
    scanf("%s", &s);
    for(i=0; i<(N-1); i++) {
        if(s[i]==s[i+1])
            count++;
    }
    printf("%d", count);
    return 0;
}