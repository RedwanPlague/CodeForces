#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
 
const int MX = 30;
const int MOD = 1000000007;
 
int main()
{
    int T;
    string s;
    cin >> T;
    while(T--)
    {
        cin >> s;
        int l = 0, u = 0, d = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                l++;
            else if(s[i] >= 'A' && s[i] <= 'Z')
                u++;
            else
                d++;
        }
        if(l == 0 && u == 0)
        {
            s[0] = 'a';
            s[1] = 'A';
        }
        else if(u == 0 && d == 0)
        {
            s[0] = '1';
            s[1] = 'A';
        }
        else if(d == 0 && l == 0)
        {
            s[0] = 'a';
            s[1] = '1';
        }
        else if(l == 0)
        {
            if(u > 1)
            {
                for(int i=0; i<s.length(); i++)
                {
                    if(s[i] >= 'A' && s[i] <='Z')
                    {
                        s[i] = 'a';
                        break;
                    }
                }
            }
            else
            {
                for(int i=0; i<s.length(); i++)
                {
                    if(s[i] >= '0' && s[i] <='9')
                    {
                        s[i] = 'a';
                        break;
                    }
                }
            }
        }
        else if(u == 0)
        {
            if(l > 1)
            {
                for(int i=0; i<s.length(); i++)
                {
                    if(s[i] >= 'a' && s[i] <='z')
                    {
                        s[i] = 'A';
                        break;
                    }
                }
            }
            else
            {
                for(int i=0; i<s.length(); i++)
                {
                    if(s[i] >= '0' && s[i] <='9')
                    {
                        s[i] = 'A';
                        break;
                    }
                }
            }
        }
        else if(d == 0)
        {
            if(u > 1)
            {
                for(int i=0; i<s.length(); i++)
                {
                    if(s[i] >= 'A' && s[i] <='Z')
                    {
                        s[i] = '1';
                        break;
                    }
                }
            }
            else
            {
                for(int i=0; i<s.length(); i++)
                {
                    if(s[i] >= 'a' && s[i] <='z')
                    {
                        s[i] = '1';
                        break;
                    }
                }
            }
        }
 
        cout << s << br;
 
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 