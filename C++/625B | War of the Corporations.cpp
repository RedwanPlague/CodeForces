#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string s, t;
    cin>>s>>t;
    int cnt = 0,
    lt = t.length();
    size_t f = 0;
    while((f = s.find(t,f)) != string::npos)
    {
        f += lt;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}