#include <bits/stdc++.h>
using namespace std;
map <char,int> mp;
int main()
{
    
    int n;
    char a, b;
    cin>>a>>b>>n;
    int fi, se;
    mp['V'] = 0;
    mp['<'] = 1;
    mp['^'] = 2;
    mp['>'] = 3;
    fi = mp[a];
    se = mp[b];
    int cw = fi + n%4;
    cw %= 4;
    int ccw = fi - n%4;
    if(ccw<0)
        ccw += 4;
    if(cw==se && ccw==se)
        cout<<"undefined"<<endl;
    else if(cw==se)
        cout<<"cw"<<endl;
    else
        cout<<"ccw"<<endl;
    return 0;
}