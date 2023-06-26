#include <bits/stdc++.h>
using namespace std;
 
#define br '\n'
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 31;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin>>n;
 
    int a[] = {100, 20, 10, 5, 1};
 
    int cnt = 0;
 
    for(int i=0; i<5; i++)
    {
        while(n >= a[i])
        {
            n -= a[i];
            cnt++;
        }
    }
 
    cout<<cnt<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 