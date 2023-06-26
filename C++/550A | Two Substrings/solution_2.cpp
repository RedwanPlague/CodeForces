// Ei problem ta te ajk 4 bar mara khailam. matha purai gorom. this is the 5th trial. 
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l = s.length(), 
    i, f = 0; 
    for(i=1; i<l; i++)
    {
        if(s[i-1] == 'A' && s[i] == 'B')
        {
            f++;
            break;
        }
    }
    for(i+=2; i<l; i++)
    {
        if(s[i-1] == 'B' && s[i] == 'A')
        {
            f++;
            break;
        }
    }
    if(f==2)
    {
        puts("YES");
        return 0;
    }
    f = 0;
    for(i=1; i<l; i++)
    {
        if(s[i-1] == 'B' && s[i] == 'A')
        {
            f++;
            break;
        }
    }
    for(i+=2; i<l; i++)
    {
        if(s[i-1] == 'A' && s[i] == 'B')
        {
            f++;
            break;
        }
    }
    if(f==2)
        puts("YES");
    else
        puts("NO");
    return 0;
}