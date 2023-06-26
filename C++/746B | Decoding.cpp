#include <cstdio>
#include <cstdlib>
int main()
{
    int l;
    char *s = (char*)calloc(l+1,sizeof(char));
    char *a = (char*)calloc(l+1,sizeof(char));
    scanf("%d %s", &l, s);
    int i, fr=0, bk=l-1;
    for(i=l-1; i>=0; i--)
    {
        if((i+l+1)%2)a[fr++] = s[i];
        else a[bk--] = s[i];
    }
    puts(a);
    return 0;
}