#include <stdio.h>
char s[6]="heidi";
int main()
{
    int i=0;
    char c;
    while((c=getchar())!='\n') {
        if(c==s[i]) {
            i++;
        }
    }
    if(i==5) printf("YES");
    else printf("NO");
    return 0;
}