#include <stdio.h>
#include <string.h>
int main()
{
    int i, l, lucky=0;
    char s[19];
    scanf("%s", &s);
    l=strlen(s);
    for(i=0; i<l; i++) {
        if(s[i]=='7' || s[i]=='4')
            lucky++;
    }
    if(lucky==4 || lucky==7)
        printf("YES");
    else
        printf("NO");
    return 0;
}