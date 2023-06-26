#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    cin>>n;
    char a[n][n+1];
    for(i=0; i<n; i++)
        scanf("%s", a[i]);
    int mx = 0, same;
    for(i=0; i<n; i++)
    {
        same = 0;
        for(j=0; j<n; j++)
        {
            if(!strcmp(a[i],a[j]))
                same++;
        }
        mx = max(mx,same);
    }
    cout<<mx<<endl;
    return 0;
}