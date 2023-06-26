#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
#define MX 35
#define MOD 1'000'000'007
#define F first
#define S second
#define br '\n'
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int n = s.size()+1;
        int ones = 0, zeros = 0;
        vi one(n);
        for (int i=0; i<s.size(); i++)
        {
            (s[i] == '0') ? zeros++ : ones++;
            one[i+1] = ones;
        }
 
        int min_moves = n;
        for (int i=0; i<n; i++)
        {
            int one_left = one[i];
            int one_right = ones - one_left;
            int zero_left = i - one_left;
            int zero_right = zeros - zero_left;
            int moves = min(one_left + zero_right, zero_left + one_right);
            min_moves = min(min_moves, moves);
        }
 
        cout << min_moves << br;
    }
 
    return 0;
}