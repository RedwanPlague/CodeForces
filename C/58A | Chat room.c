#include <stdio.h>
#include <string.h>
int main()
{
    int i, l, f=0;
    char s[101];
    scanf("%s", &s);
    l=strlen(s);
    if(l<5)
        printf("NO");
    else
    {
        i=0;
        while(i<l) {
            if(s[i]=='h')
                break;
            i++;
        }
        i++;
        while(i<l) {
            if(s[i]=='e')
                break;
            i++;
        }
        i++;
        while(i<l) {
            if(s[i]=='l')
                break;
            i++;
        }
        i++;
        while(i<l) {
            if(s[i]=='l')
                break;
            i++;
        }
        i++;
        while(i<l) {
            if(s[i]=='o')
                break;
            i++;
        }
        if(i<l)
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}