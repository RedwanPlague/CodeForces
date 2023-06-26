#include <stdio.h>
#include <ctype.h>
 
int main()
{
    int i, n, a[26]={0};
    char c;
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++) {
        c=tolower(getchar());
        a[c-'a']=1;
    }
    for(i=0; i<26; i++) if(a[i]!=1) {
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}