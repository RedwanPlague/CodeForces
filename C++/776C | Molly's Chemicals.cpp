#include <iostream>
#include <vector>
#include <map>
 
#define MX 1'000'000'000'000'10
 
using namespace std;
 
typedef long long ll;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
 int n;
 ll k;
 cin >> n >> k;
 
 vector<ll> powers;
 
 if(k == 1)
     powers.push_back(1);
 else if(k == -1)
 {
     powers.push_back(1);
     powers.push_back(-1);
 }
 else 
 {
     for(ll i=1; abs(i)<MX; i*=k) 
     {
         powers.push_back(i);
     }
 }
 
 vector<ll> v(n), pre(n+1);
 pre[0] = 0;
 for(int i=0; i<n; i++)
 {
     cin >> v[i];
     pre[i+1] = pre[i] + v[i];
 }
 
 ll ways = 0;
 for(int i=0; i<powers.size(); i++)
 {
     map<ll,int> mp;
     mp[pre[n]] = 1;
     for(int j=n-1; j>=0; j--)
     {
         ways += mp[powers[i]+pre[j]];
         mp[pre[j]]++;
     }
 }
 
 cout << ways << endl;
 
 return 0;
}