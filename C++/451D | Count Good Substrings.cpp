#include <iostream>
#include <string>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    string s;
    cin >> s;
    int len = s.size(); // cause i < (int)s.size() is a pain
    ll odd = len, even = 0, ao = 0, bo = 0, ae = 0, be = 0;
 
    for(int i=0; i<len; i++)
    {
        if(s[i] == 'a')
        {
            if(i&1)
            {
                odd += ao;
                even += ae;
                ao++;
            }
            else
            {
                odd += ae;
                even += ao;
                ae++;
            }
        }
        else
        {
            if(i&1)
            {
                odd += bo;
                even += be;
                bo++;
            }
            else
            {
                odd += be;
                even += bo;
                be++;
            }
        }
    }
 
    cout << even << ' ' << odd << endl;
 
    return 0;
}