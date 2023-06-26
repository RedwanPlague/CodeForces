#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false); cout.tie(false);
    
    vector <int> v;
    v.push_back(1);
    for(int k=2; v.back() < 100005; k++)
    {
        v.push_back( ((1<<k)-1) * (1<<(k-1)) );
        //cout<<v.back()<<' ';
    }
    
    int n;
    cin>>n;
    
    for(int i=v.size()-1; i>=0; i--)
    {
        if(n%v[i] == 0)
        {
            cout<<v[i]<<endl;
            break;
        }
    }
    
    return 0;
}