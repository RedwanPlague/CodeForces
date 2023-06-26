#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *a[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    char s[10];
    int l, n, i, j;
    scanf("%d %s", &n, s);
    int *b = (int*)calloc(8,sizeof(int));
    int mx = 0;
    for(i=0; i<8; i++)
    {
        l = strlen(a[i]);
        if(n!=l)
            continue;
        for(j=0; j<n; j++)
            if(s[j]==a[i][j])
                b[i]++;
        if(mx<b[i])
            mx = b[i];
    }
    for(i=0; i<8; i++)
    {
        if(b[i]==mx && strlen(a[i])==n)
        {
            puts(a[i]);
            break;
        }
    }
 return 0;
}