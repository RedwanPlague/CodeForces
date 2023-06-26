#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;
    int n, point, amaz=0;
    cin>>n;
    cin>>point;
    v.push_back(point);
    n--;
    while(n--) {
        cin>>point;
        if(point<*min_element(v.begin(),v.end()) || point>*max_element(v.begin(),v.end())) amaz++;
        v.push_back(point);
    }
    cout<<amaz<<endl;
    return 0;
}