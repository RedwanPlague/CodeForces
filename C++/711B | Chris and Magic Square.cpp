#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[501][501], Sr[501], Sc[501], Sd1, Sd2, S;
int main()
{
    int n, i, j, r, c;
    cin>>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>a[i][j];
            Sr[i] += a[i][j];
            Sc[j] += a[i][j];
            if( !a[i][j] )
            {
                r = i;
                c = j;
            }
        }
    }
    S = max(Sr[0],Sr[n-1]);
    if(!S) S=1;
    a[r][c] = S-Sr[r];
    if(a[r][c]<=0)
        goto none;
    Sr[r] += a[r][c];
    Sc[c] += a[r][c];
    for(i=0; i<n; i++)
    {
        if( Sr[i] != S )
            goto none;
    }
    for(j=0; j<n; j++)
    {
        if( Sc[j] != S )
            goto none;
    }
    for(i=0,j=n-1; i<n; i++,j--)
    {
        Sd1 += a[i][i];
        Sd2 += a[i][j];
    }
    if( Sd1 != S || Sd2 !=  S )
        goto none;
    cout<<a[r][c]<<endl;
    return 0;
    none:
        puts("-1");
    return 0;
}