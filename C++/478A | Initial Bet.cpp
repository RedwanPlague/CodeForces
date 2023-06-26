#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int c, S=0;
    for(int i=0; i<5; i++) {
        cin>>c;
        S+=c;
    }
    if(S%5==0 && S!=0) cout<<S/5<<endl;
    else cout<<"-1"<<endl;
    return 0;
}