#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    vector<bool> mark(26,false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char c;
    while(k--)
    {
        cin >> c;
        mark[c-'a'] = true;
    }
    long long cnt = 0;
    long long sum = 0;
    for(int i=0; i<n; i++)
    {
        if(mark[s[i]-'a'])
            cnt++;
        else
        {
            sum += (cnt*(cnt+1))/2;
            cnt = 0;
        }
    }
    sum += (cnt*(cnt+1))/2;
 
    cout << sum << endl;
 
    return 0;
}