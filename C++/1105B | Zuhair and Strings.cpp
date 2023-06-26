#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt[26];
 
    int idx = 0;
    while(idx<n)
    {
        int sum = 1;
        while(idx<n && s[idx] == s[idx+1])
        {
            idx++;
            sum++;
        }
        if(idx == n)
            idx--;
        cnt[s[idx]-'a'].push_back(sum);
        idx++;
    }
 
    int mx = 0;
    for(int i=0; i<26; i++)
    {
        int sum = 0;
        for(int j=0; j<cnt[i].size(); j++)
            sum += cnt[i][j] / k;
        if(sum > mx)
            mx = sum;
    }
 
    cout << mx << endl;
 
    return 0;
}
 