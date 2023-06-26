#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    char *s = (char*)calloc(n+1,sizeof(char));
    scanf("%s", s);
    int i = 0;
    while(i<n)
    {
        if(s[i]=='o' && s[i+1]=='g' && s[i+2]=='o')
        {
            i += 3;
            while(s[i]=='g' && s[i+1]=='o') 
                i += 2;
            printf("***");
        }
        else
            putchar(s[i++]);
    }
    return 0;
}