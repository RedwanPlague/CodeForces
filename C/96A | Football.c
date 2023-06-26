#include <stdio.h>
#include <string.h>
main()
{
    int i, l, j, f;
    char s[101];
    scanf("%s", &s);
    l=strlen(s);
    if(l<7)
        printf("NO\n");
    else {
    for(i=0; i<=(l-7); i++) {
        if(s[i]==s[i+1] && s[i]==s[i+2] && s[i]==s[i+3] && s[i]==s[i+4] && s[i]==s[i+5] && s[i]==s[i+6])
            break;
    }
    if(i==(l-6))
        printf("NO\n");
    else
        printf("YES\n");
    }
}