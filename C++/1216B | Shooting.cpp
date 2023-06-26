#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end(),greater<pii>());
 
    ll shots = 0;
    for(int i=0; i<n; i++)
    {
        shots += (v[i].first*i) + 1;
    }
    cout << shots << '\n';
    for(int i=0; i<n; i++)
        cout << v[i].second << ' ';
    cout << endl;
 
    return 0;
}