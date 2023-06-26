#include <stdio.h>
#include <string.h>
int main()
{
    int i=0, l, f=0;
    char s[201];
    scanf("%s", &s);
    l=strlen(s);
    while(i<l)
    {
        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') {
            if(f==1) {
                printf(" ");
                f=0;
            }
            i+=3;
        }
        else {
            printf("%c", s[i]);
            f=1;
            i++;
        }
    }
    return 0;
}