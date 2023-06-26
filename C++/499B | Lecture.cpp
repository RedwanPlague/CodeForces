#include <bits/stdc++.h>
using namespace std;
map <string, string> mp;
int main()
{
    int n, m;
    string fir, sec;
    cin>>n>>m;
    while(m--)
    {
        cin>>fir>>sec;
        mp[fir] = sec;
    }
    while(n--)
    {
        cin>>fir;
        if(mp[fir].length()<fir.length())
            cout<<mp[fir]<<' ';
        else 
            cout<<fir<<' ';
    }
    cout<<endl;
    return 0;
}