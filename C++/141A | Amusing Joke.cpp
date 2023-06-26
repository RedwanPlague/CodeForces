#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a=(int*)calloc(26,sizeof(int));
    int *b=(int*)calloc(26,sizeof(int));
    char c;
    while((c=getchar())!='\n') a[c-'A']++;
    while((c=getchar())!='\n') a[c-'A']++;
    while((c=getchar())!='\n') b[c-'A']++;
    int i;
    for(i=0; i<26; i++) {
        if(a[i]!=b[i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}