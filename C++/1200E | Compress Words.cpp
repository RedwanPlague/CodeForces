#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int kmp(const string &s)
{
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi.back();
}
 
void combine(string &cur, string &s)
{
    if(cur.size() > s.size())
    {
        string temp = s + '$' + cur.substr(cur.size() - s.size());
        int idx = kmp(temp);
        cur += s.substr(idx);
    }
    else
    {
        string temp = s.substr(0, cur.size()) + '$' + cur;
        int idx = kmp(temp);
        cur += s.substr(idx);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++)
        cin >> s[i];
 
    string cur = s[0];
    for(int i=1; i<n; i++)
    {
        combine(cur,s[i]);
    }
 
    cout << cur << endl;
 
    return 0;
}