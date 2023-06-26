#include <cstdio>
#include <cstring>
 
#define MX 100005
 
int main()
{
    char a[MX], b[MX];
    scanf("%s %s", a, b);
    int pre[MX], suf[MX];
 
    int la = strlen(a);
    int lb = strlen(b);
 
    for(int i=0, j=0; i<lb; i++, j++)
    {
        while(j < la && a[j] != b[i])
            j++;
        pre[i] = (j < la) ? j : MX;
    }
 
    for(int i=lb-1, j=la-1; i>=0; i--, j--)
    {
        while(j >= 0 && a[j] != b[i])
            j--;
        suf[i] = (j >= 0) ? j : -1;
    }
 
    /*for(int i=0; i<lb; i++)
        printf("%d ", pre[i]);
    putchar('\n');
    for(int i=0; i<lb; i++)
        printf("%d ", suf[i]);
    putchar('\n');*/
 
    int mn = MX, ansi = -1, ansj = -1;
 
    for(int i=lb-1; i>=0; i--) // if a prefix is taken (i.e: suffix is erased)
    {
        if(pre[i] != MX && (lb - i - 1) < mn)
        {
            mn = lb - i - 1;
            ansi = i;
            ansj = lb;
            break;
        }
    }
 
    for(int i=0; i<lb; i++) // if a suffix is taken (i.e: prefix is erased)
    {
        if(suf[i] != -1 && i < mn)
        {
            mn = i;
            ansi = -1;
            ansj = i;
            break;
        }
    }
 
    for(int i=0; i<lb; i++) // if a part from the middle is erased
    {
        int j = i+1;
        while(j < lb && pre[i] >= suf[j])
            j++;
        if(pre[i] < suf[j] && (j-i-1) < mn)
        {
            mn = j - i - 1;
            ansi = i;
            ansj = j;
        }
    }
 
    if(mn == MX)
        puts("-");
    else
    {
        for(int i=0; i<=ansi; i++)
            putchar(b[i]);
        for(int i=ansj; i<lb; i++)
            putchar(b[i]);
        putchar('\n');
    }
 
    return 0;
}