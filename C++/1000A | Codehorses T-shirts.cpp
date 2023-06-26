#include <bits/stdc++.h>
using namespace std;
 
#define br '\n'
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 105;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    int n;
    cin>>n;
 
    string s;
 
    vector <string> gr[5];
 
    for(int i=0; i<n; i++)
    {
        cin>>s;
        gr[s.length()].push_back(s);
    }
 
    vector <string> nr[5];
 
    for(int i=0; i<n; i++)
    {
        cin>>s;
        nr[s.length()].push_back(s);
    }
 
    int cnt = 0;
 
    int M = 0, S = 0, L = 0;
 
    for(int j=0; j<gr[1].size(); j++)
    {
        if(gr[1][j] == "M")
            M++;
        else if(gr[1][j] == "S")
            S++;
        else
            L++;
    }
 
    for(int j=0; j<nr[1].size(); j++)
    {
        if(nr[1][j] == "M")
            M--;
        else if(nr[1][j] == "S")
            S--;
        else
            L--;
    }
 
    if(M > 0)
        cnt += M;
    if(S > 0)
        cnt += S;
    if(L > 0)
        cnt += L;
 
    for(int i=2; i<=4; i++)
    {
        string look = "";
        for(int j=1; j<i; j++)
            look += "X";
        look += "S";
        int a = 0, b = 0;
        for(int j=0; j<gr[i].size(); j++)
        {
            if(gr[i][j] == look)
                a++;
        }
        for(int j=0; j<nr[i].size(); j++)
        {
            if(nr[i][j] == look)
                b++;
        }
        cnt += abs(a-b);
    }
 
    cout<<cnt<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 