#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
 
const int MX = 1005;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m;
    cin>>n>>m;
    int game[MX], note[MX];
    for(int i=0; i<n; i++)
        cin>>game[i];
    for(int i=0; i<m; i++)
        cin>>note[i];
 
    int i = 0, j = 0, cnt = 0;
 
    while(i < n && j < m)
    {
        if(note[j] >= game[i])
        {
            i++;
            j++;
            cnt++;
        }
        else
            i++;
    }
 
    cout<<cnt<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 