#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
typedef vector<int> vi;
 
vi pi;
vector <vi> aut, dp;
string text, word;
 
void prefix_func(const string &s)
{
    int n = s.length();
    pi.resize(n);
    pi[0] = 0;
    for(int i=1; i<n; i++)
    {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
}
 
void build_auto(const string &s)
{
    int n = s.length();
    aut.assign(n, vi(26));
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}
 
int max_anthem(const int idx, int match)
{
    if(idx == text.size())
        return 0;
 
    if(dp[idx][match] != -1)
        return dp[idx][match];
 
    if(text[idx] != '?')
    {
        int new_match = aut[match][text[idx]-'a'];
        int add = 0;
        if(new_match == word.size())
        {
            new_match = pi[new_match-1];
            add++;
        }
        return (dp[idx][match] = add+max_anthem(idx+1,new_match));
    }
 
    int ret = 0;
    for(int i=0; i<26; i++)
    {
        int new_match = aut[match][i];
        int add = 0;
        if(new_match == word.size())
        {
            new_match = pi[new_match-1];
            add++;
        }
        ret = max(ret,add+max_anthem(idx+1,new_match));
    }
    return (dp[idx][match] = ret);
}
 
int main()
{
    cin >> text >> word;
 
    vi pi;
    prefix_func(word);
    build_auto(word);
 
    dp.assign(text.size(),vi(word.size()+1,-1));
 
    cout << max_anthem(0,0) << endl;
 
    return 0;
}