#include <stdio.h>
#include <string.h>
int main()
{
    int f=0, i, l;
    char s[1001];
    scanf("%s", &s);
    l=strlen(s);
    for(i=0; i<l; i++) {
        switch(s[i]) {
    case 'H':
    case 'Q':
    case '9':
        f=1;
        break;
        }
    if(f==1)
        break;
    }
    if(f==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}