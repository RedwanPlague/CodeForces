#include <stdio.h>
 
int main()
{
    int a[26]={0}, distinct=0;
    char letter, comma=',';
    getchar();
    while(comma==',' && letter!='}') {
        scanf("%c%c%*c", &letter, &comma);
        a[letter-'a']=1;
    }
    for(int i=0; i<26; i++)
        if(a[i]==1) distinct++;
    printf("%d", distinct);
    return 0;
}