#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
vi prefix_func(const string &s)
{
    int len = s.length();
    vi pi(len);
    pi[0] = 0;
    for(int i=1; i<len; i++)
    {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
int main()
{
 string s;
 cin >> s;
 
 int n = s.size();
 
 vi pi = prefix_func(s);
 
 vi cnt(n + 1,0);
    for (int i = 0; i < n; i++)
        cnt[pi[i]]++;
    for (int i = n-1; i > 0; i--)
        cnt[pi[i-1]] += cnt[i];
    for (int i = 0; i <= n; i++)
        cnt[i]++;
        
    vector<bool> mark(n+1,0);
    int len = pi[n-1];
    while(len > 0)
    {
        mark[len] = 1;
        len = pi[len-1];
    }
    
    int sum = 1;
    
    for(int i=1; i<=n; i++)
        if(mark[i])
            sum++;
            
    cout << sum << endl;
    for(int i=1; i<=n; i++)
        if(mark[i])
            cout << i << " " << cnt[i] << "\n";
 cout << n << " " << 1 << endl;
 
 return 0;
}