#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define F first
#define S second
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,char> plc;
 
vi kmp(const vector<plc> &s)
{
    int n = (int)s.size();
    vi pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
bool contains(plc a, plc b)
{
    return (a.S == b.S && a.F >= b.F);
}
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    vector<plc> t, s;
 
    ll l, len;
    char c, prev;
 
    scanf("%lld-%c", &l, &c);
    len = l;
    prev = c;
    for(int i=1; i<n; i++)
    {
        scanf("%lld-%c", &l, &c);
        if(prev != c)
        {
            t.emplace_back(len,prev);
            len = l;
            prev = c;
        }
        else
            len += l;
    }
    t.emplace_back(len,prev);
 
    scanf("%lld-%c", &l, &c);
    len = l;
    prev = c;
    for(int i=1; i<m; i++)
    {
        scanf("%lld-%c", &l, &c);
        if(prev != c)
        {
            s.emplace_back(len,prev);
            len = l;
            prev = c;
        }
        else
            len += l;
    }
    s.emplace_back(len,prev);
 
    /*for(int i=0; i<t.size(); i++)
        printf("%d-%c ", t[i].F, t[i].S);
    putchar('\n');
 
    for(int i=0; i<s.size(); i++)
        printf("%d-%c ", s[i].F, s[i].S);
    putchar('\n');*/
 
    ll cnt = 0;
 
    if(s.size() == 1)
    {
        l = s.front().F;
        c = s.front().S;
        for(int i=0; i<t.size(); i++)
        {
            if(t[i].S == c && t[i].F >= l)
                cnt += t[i].F - l + 1;
        }
        printf("%lld\n", cnt);
    }
    else
    {
        plc f = s.front(), b = s.back();
        s.erase(s.begin());
        s.pop_back();
        l = s.size();
        s.emplace_back(1,'$');
        s.insert(s.end(),t.begin(),t.end());
        vi pi = kmp(s);
        for(int i=2*l+1; i+1<s.size(); i++)
        {
            if(pi[i] == l && contains(s[i-l],f) && contains(s[i+1],b))
                cnt++;
        }
        printf("%lld\n", cnt);
    }
 
    return 0;
}