#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1005][4];
int main()
{
    int n, i;
    scanf("%d%*c", &n);
    for(i=0; i<n; i++)
        scanf("%c%c%*c%c%c%*c", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    int f=0;
    for(i=0; i<n; i++)
    {
        if(a[i][0]=='O' && a[i][1]=='O')
        {
            a[i][0] = '+';
            a[i][1] = '+';
            f = 1;
            break;
        }
        else if(a[i][2]=='O' && a[i][3]=='O')
        {
            a[i][2] = '+';
            a[i][3] = '+';
            f = 1;
            break;
        }
    }
    if(!f)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(i=0; i<n; i++)
    {
        printf("%c%c|%c%c\n", a[i][0], a[i][1], a[i][2], a[i][3]);
    }
    return 0;
}