#include <stdio.h>
int main()
{
    int i, N, F=0;
    char s[13];
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%s", &s);
        switch(s[0]) {
    case 'T':
        F+=4;
        break;
    case 'C':
        F+=6;
        break;
    case 'O':
        F+=8;
        break;
    case 'D':
        F+=12;
        break;
    case 'I':
        F+=20;
        break;
        }
    }
    printf("%d", F);
    return 0;
}