#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    string s;
    cin>>n>>k;
    cin>>s;
    int i;
    for(i=0; i<n; i++)
        if(s[i]=='G' || s[i]=='T')
            break;
    int f = 0;
    for(i+=k; i<n; i+=k)
    {
        if(s[i]=='#')
            break;
        if(s[i]=='G' || s[i]=='T')
        {
            f = 1;
            break;
        }
    }
    if(f)
        puts("YES");
    else 
        puts("NO");
    return 0;
}