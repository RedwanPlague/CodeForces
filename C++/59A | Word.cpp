#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[101];
    scanf("%s", s);
    int l=strlen(s);
    int i, up=0, lo=0;
    for(i=0; i<l; i++) if(s[i]>='A' && s[i]<='Z') up++; else lo++;
    if(up>lo)  for(i=0; i<l; i++) s[i]=toupper(s[i]);
    else for(i=0; i<l; i++) s[i]=tolower(s[i]);
    puts(s);
    return 0;
}