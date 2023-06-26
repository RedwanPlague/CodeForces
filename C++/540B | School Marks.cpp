#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int n, k, x, y, p, S=0;
    cin>>n>>k>>p>>x>>y;
    int i, a, upl=0, sml=0;
    vector <int> v;
    for(i=0; i<k; i++) {
        cin>>a;
        S+=a;
        if(a>=y) upl++;
    }
    int mid=(n+1)/2;
    if((mid-upl)>(n-k)) {
        puts("-1");
        return 0;
    }
    while(upl<mid) {
        v.push_back(y);
        S+=y;
        k++;
        upl++;
    }
    while(k<n) {
        v.push_back(1);
        S+=1;
        k++;
    }
    if(S>x) {
        puts("-1");
        return 0;
    }
    sort(v.begin(),v.end());
    vector <int> :: iterator it;
    for(it=v.begin(); it<v.end(); it++) printf("%d ", *it);
    cout<<endl;
    return 0;
}