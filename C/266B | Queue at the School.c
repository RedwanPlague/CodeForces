#include <stdio.h>
int main()
{
    int N, i, t, j;
    scanf("%d %d", &N, &t);
    char s[N+1];
    scanf("%s", &s);
    for(j=0; j<t; j++) {
    i=0;
    while(i<(N-1))
    {
        if(s[i]=='B' && s[i+1]=='G') {
            s[i]='G';
            s[i+1]='B';
            i+=2;
        }
        else
            i++;
    } }
    printf("%s\n", s);
    return 0;
}