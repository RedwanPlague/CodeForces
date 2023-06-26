#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    string sarr[] = {".", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm"};
 
    map<string,int> mp;
    for(int i=1; i<=100; i++)
        mp[sarr[i]] = i;
 
    int n, k;
    string s;
    cin >> n >> k;
    vi given(n), make(k);
    for(int i=0; i<n; i++)
    {
        cin >> s;
        given[i] = mp[s];
    }
    for(int i=0; i<k; i++)
    {
        cin >> s;
        make[i] = mp[s];
    }
 
    int limit = (1<<n);
    vector<ll> sum(limit), dp(limit,0);
 
    for(int mask=0; mask<limit; mask++)
    {
        sum[mask] = 0;
        for(int i=0; (1<<i)<=mask; i++)
        {
            if(mask&(1<<i))
                sum[mask] += given[i];
        }
    }
 
    for(int mask=0; mask<limit; mask++)
    {
        for(int sub=mask; sub; sub = (sub-1)&mask)
        {
            if(sum[sub] == make[dp[mask^sub]])
                dp[mask] = max(dp[mask], dp[mask^sub] + 1);
        }
        //cout << mask << " -> " << dp[mask] << endl;
    }
 
    if(dp[limit-1] != k)
    {
        cout << "NO" << endl;
        return 0;
    }
 
    cout << "YES" << endl;
 
    int cur = limit - 1;
    int done = k;
    while(cur)
    {
        for(int sub=cur; sub; sub = (sub-1)&cur)
        {
            if(dp[cur^sub] == done-1)
            {
                for(int i=0; (1<<i)<=sub; i++)
                {
                    if(sub&(1<<i))
                    {
                        cout << sarr[given[i]];
                        if((1<<(i+1))<sub)
                            cout << "+";
                    }
                }
                done--;
                cout << "->" << sarr[make[done]] << endl;
                cur ^= sub;
                break;
            }
        }
    }
 
    return 0;
}