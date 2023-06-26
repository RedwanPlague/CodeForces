#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
 
#define MX 30
#define MOD 1000000007
#define pb push_back
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int n, who;
    cin>>n;
    string s;
 
    vector<ii> seat(n);
    for(int i=0; i<n; i++)
    {
        cin>>seat[i].first;
        seat[i].second = i+1;
    }
 
    sort(seat.begin(), seat.end());
 
    priority_queue <ii> que;
 
    cin>>s;
 
    int it = 0;
 
    for(int i=0; i<2*n; i++)
    {
        who = s[i] - '0';
        if(who == 0)
        {
            cout<<seat[it].second<<' ';
            que.push(seat[it]);
            it++;
        }
        else
        {
            int where = que.top().second;
            cout<<where<<' ';
            que.pop();
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 