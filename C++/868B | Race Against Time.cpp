#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    int h, m, s, t1, t2;
    cin>>h>>m>>s>>t1>>t2;
    if(t1>t2)
        swap(t1,t2);
    t2 *= 3600;
    t1 = (3600*t1 + 12*3600 - t2) % ( 12*3600 );
    h = ( 3600*h + 60*m + s + 12*3600 - t2 ) % ( 12*3600 );
    m = ( 720*m + 12*s + 12*3600 - t2 ) % ( 12*3600 );
    s = ( 720*s + 12*3600 - t2 ) % ( 12*3600 );
    //cout<<h<<' '<<m<<' '<<s<<' '<<t1<<' '<<t2<<endl;
    if( (h<t1 && m<t1 && s<t1) || (h>t1 && m>t1 && s>t1) )
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}