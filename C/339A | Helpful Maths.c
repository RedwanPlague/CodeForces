#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, l;
    char s[101], x;
    scanf("%s", &s);
    l=strlen(s);
    for(i=0; i<l-2; i+=2) {
        for(j=i+2; j<l; j+=2)
        if(s[j]<s[i]) {
            x=s[i];
            s[i]=s[j];
            s[j]=x;
        }
    }
    printf("%s\n", s);
    return 0;
}