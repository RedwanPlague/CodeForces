#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false); cout.tie(false);
    
    int n, win, spect = 3;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        cin>>win;
        if(win == spect)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        spect = (6 - spect - win);
        //cout<<spect<<' ';
    }
    
    cout<<"YES"<<endl;
    
    return 0;
}