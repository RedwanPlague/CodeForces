#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define pb push_back
vector <int> prime;
void sieve()
{
    vector <bool> mark(MAX,true);
    prime.pb(2);
    for(int i=3; i<MAX; i+=2)
    {
        if(!mark[i])
            continue;
        prime.pb(i);
        for(int j=i*i; j<MAX; j+=2*i)
            mark[j] = false;
    }
}
int main()
{
    sieve();
    int gun, N;
    vector <int> ans;
    cin>>N;
    for(int i=0; prime[i]<=N; i++)
    {
        gun = prime[i];
        while(gun<=N)
        {
            ans.pb(gun);
            gun *= prime[i];
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}