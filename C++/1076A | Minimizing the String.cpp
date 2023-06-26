#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 105;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int N;
    cin >> N;
    string s;
    cin >> s;
    int idx = s.size() - 1;
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i] > s[i+1])
        {
            idx = i;
            break;
        }
    }
 
    for(int i=0; i<s.size(); i++)
    {
        if(i != idx)
            cout << s[i];
    }
    cout << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 