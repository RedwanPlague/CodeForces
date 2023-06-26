#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
 
vi suffix_array(string const& s)
{
    int n = s.size();
    const int alphabet = 256;
    vi p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vi pn(n), cn(n);
    for (int h = 1; h < n; h <<= 1)
    {
        for (int i = 0; i < n; i++)
        {
            pn[i] = p[i] - h;
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++)
        {
            pair<int, int> cur = {c[p[i]], c[(p[i] + h) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + h) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
 
vi lcp_construction(string const& s, vi const& p)
{
    int n = s.size();
    vi rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
 
    int k = 0;
    vi lcp(n-1, 0);
    for (int i = 0; i < n; i++)
    {
        if (rank[i] == n - 1)
        {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    string a, b;
    cin >> a >> b;
    string mer = a + '$' + b + '#';
 
    vi p = suffix_array(mer);
    vi lcp = lcp_construction(mer,p);
    lcp.push_back(0);
 
    /*for(int i=0; i<p.size(); i++)
    {
        cout << lcp[i] << ' ' << mer.substr(p[i]) << endl;
    }*/
 
    int mn = mer.size(), idx = -1;
    for(int i=2; i<mer.size()-1; i++)
    {
        if(min(p[i],p[i+1]) < a.size() && max(p[i],p[i+1]) > a.size() && lcp[i] > lcp[i-1] && lcp[i] > lcp[i+1] && max(lcp[i-1],lcp[i+1])+1 < mn)
        {
            mn = max(lcp[i-1],lcp[i+1])+1;
            idx = i;
        }
    }
 
    if(mn == mer.size())
        mn = -1;
    cout << mn << endl;
    /*if(idx >= 0)
        cout << mer.substr(p[idx],mn) << ' ' << mer.substr(p[idx+1],mn) << endl;*/
 
    return 0;
}