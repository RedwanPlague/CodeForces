#include <iostream>
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int pearl = 0, link = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == 'o')
            pearl++;
        else
            link++;
    }
    if(pearl == 0 || link%pearl == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}