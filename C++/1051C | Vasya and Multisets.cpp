#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
 
const int MX = 105;
const int MOD = 1000000007;
 
int mark[MX], a[MX];
 
int main()
{
    int n, cnt = 0, cnt1 = 0;
    cin >> n;
 
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        mark[a[i]]++;
    }
 
    for(int i=0; i<MX; i++)
    {
        if(mark[i] == 1)
            cnt++;
        else if(mark[i] > 2)
            cnt1++;
    }
 
    if((cnt&1) && !cnt1)
    {
        cout << "NO" <<endl;
        return 0;
    }
 
    cout << "YES\n";
 
    int vag = 0;
    if(cnt&1)
        vag = 1;
 
    cnt /= 2;
 
    for(int i=0; i<n; i++)
    {
        if(mark[a[i]] == 1 && cnt)
        {
            cout <<'B';
            cnt--;
        }
        else if(mark[a[i]]>2 && vag)
        {
            cout <<'B';
            vag--;
        }
        else
            cout<< 'A';
    }
    cout<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 