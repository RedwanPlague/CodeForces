#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, v1, v2, t1, t2;
    cin>>l>>v1>>v2>>t1>>t2;
    int T1 = l*v1+2*t1;
    int T2 = l*v2+2*t2;
    if(T1==T2)
        cout<<"Friendship"<<endl;
    else if(T1<T2)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    return 0;
}