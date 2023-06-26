#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;
 
const int INF = (1 << 30);
 
typedef vector<int> vi;
 
void z_func(const string &p, const string &s, vi &match)
{
    string temp = p + '#' + s;
    int len = temp.size();
    int pl = p.size();
    vi z(len);
    match.assign(pl+1,INF);
    for(int i=1, l=0, r=0; i<len; i++)
    {
        z[i] = (i <= r) ? min(z[i-l], r-i+1) : 0 ;
        while(i+z[i] < len && temp[z[i]] == temp[i+z[i]])
            z[i]++;
        if(i+z[i]-1 > r)
        {
            l = i;
            r = i+z[i]-1;
        }
        if(i > pl)
        {
            match[z[i]] = min(match[z[i]], i-(pl+1));
        }
    }
    for(int i=pl-1; i>0; i--)
    {
        match[i] = min(match[i], match[i+1]);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    string text, s, rs;
    cin >> text;
    string rev = text;
    reverse(rev.begin(), rev.end());
 
    int len = text.size();
 
    int m;
    cin >> m;
    int cnt = 0;
    vi pref, suff;
    for(int i=0; i<m; i++)
    {
        cin >> s;
        if(s.size() == 1 || s.size() > len)
            continue;
        rs = s;
        reverse(rs.begin(), rs.end());
        z_func(s,text,pref);
        z_func(rs,rev,suff);
        int sl = s.size();
        if(pref[sl] != INF) // if the whole string matches
        {
            cnt++; 
            continue;
        }
        for(int i=1; i<sl; i++)
        {
            if(pref[i] != INF && suff[sl-i] != INF && pref[i]+suff[sl-i]+sl <= len)
            {
                cnt++; 
                break;
            }
        }
    }
 
    cout << cnt << endl;
 
    return 0;
}