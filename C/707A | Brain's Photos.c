#include <stdio.h>
int main()
{
    int n, m;
    char c;
    scanf("%d %d ", &n, &m);
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%c ", &c);
            if(c=='C' || c=='M' || c=='Y')
            {
                puts("#Color");
                return 0;
            }
        }
    }
    puts("#Black&White");
    return 0;
}