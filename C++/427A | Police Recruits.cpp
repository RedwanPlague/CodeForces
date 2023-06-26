#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int po = 0, unt = 0, n, a;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a>0)
            po += a;
        else if(!po)
            unt++;
        else 
            po--;
    }
    cout<<unt<<endl;
    return 0;
}