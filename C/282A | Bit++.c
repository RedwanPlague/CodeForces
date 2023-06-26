#include <stdio.h>
main()
{
    int N, i, x=0;
    char c[4];
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%s", &c);
        if(c[1]=='+')
            x++;
        else if(c[1]=='-')
            x--;
    }
    printf("%d\n", x);
}