#include <stdio.h>
#include <string.h>
int main()
{
    int l, i, f=0;
    char s1[101], s2[101];
    for(l=0; l<101; l++) {
        scanf("%c", &s1[l]);
        if(s1[l]=='\n')
            break;
        else if(s1[l]>='A' && s1[l]<='Z')
            s1[l]+='a'-'A';
    }
    for(i=0; i<l; i++) {
        scanf("%c", &s2[i]);
        if(s2[i]>='A' && s2[i]<='Z')
            s2[i]+='a'-'A';
    }
    for(i=0; i<l; i++) {
        if(s1[i]>s2[i]) {
            f=1;
            break;
        }
        else if(s1[i]<s2[i]) {
            f=-1;
            break;
        }
    }
    printf("%d\n", f);
    return 0;
}