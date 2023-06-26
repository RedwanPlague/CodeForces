#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    vector <string> v;
    while(n--)
    {
        cin>>s;
        v.push_back(s);
    }
    int mx = 0, same;
    for(auto i: v)
    {
        same = 0;
        for(auto j: v)
        {
            if(i==j)
                same++;
        }
        mx = max(mx,same);
    }
    cout<<mx<<endl;
    return 0;
}