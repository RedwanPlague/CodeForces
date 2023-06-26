#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n;
    int k;
 
    while(cin >> n >> k)
    {
        ll lim = sqrt(n+.5);
        vector<ll> dvf, dvb;
        for(ll i=1; i<lim; i++)
        {
            if(n%i == 0)
            {
                dvf.push_back(i);
                dvb.push_back(n/i);
            }
        }
        if(n%lim == 0)
        {
            dvf.push_back(lim);
            if(n/lim != lim)
                dvb.push_back(n/lim);
        }
        
        if(k > dvf.size()+dvb.size())
        {
            cout << -1 << endl;
        }
        else
        {
            k--;
            if(k < dvf.size())
            {
                cout << dvf[k] << endl;
            }
            else
            {
                k -= dvf.size();
                cout << dvb[dvb.size()-1-k] << endl;
            }
        }
    }
    
    return 0;
}