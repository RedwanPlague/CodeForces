#include <stdio.h>
#include <string.h>
int main()
{
    int i, l, count=0, a[26];
    char s[101];
    scanf("%s", &s);
    for(i=0; i<26; i++)
        a[i]=0;
    l=strlen(s);
    for(i=0; i<l; i++)
        a[s[i]-'a']++;
    for(i=0; i<26; i++)
        if(a[i]>0)
            count++;
    if(!(count%2))
        printf("CHAT WITH HER!");
    else
        printf("IGNORE HIM!");
    return 0;
}