#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    string s;
    cin>>n>>k;
    int l;
    int *a = (int*)calloc(105,sizeof(int));
    while(n--)
    {
        cin>>s;
        l = s.length();
        a[l]++;
    }
    cin>>s;
    l = s.length();
    int i, tm, S = 0;
    for(i=0; i<l; i++)
        S += a[i];
    tm = (S/k)*(k+5)+(S%k);
    cout<<tm+1<<' ';
    S += a[l];
    tm = (S/k)*(k+5)+(S%k);
    if(S%k==0)
        tm -= 5;
    cout<<tm<<endl;
    return 0;
}