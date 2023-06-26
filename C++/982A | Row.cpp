#include <iostream>
using namespace std;
 
typedef long long ll;
 
int main()
{
    int l;
    cin>>l;
    string s;
    cin>>s;
    
    bool valid = true;
    for(int i=0; i<l; i++)
    {
        if(s[i] == '1' && ((i > 0 && s[i-1] == '1') || (i < l-1 && s[i+1] == '1')))
            valid = false;
    }
    
    for(int i=0; i<l; i++)
    {
        if(s[i] == '0' && (i == 0 || s[i-1] == '0') && (i == l-1 || s[i+1] == '0'))
            valid = false;
    }
    
    if(valid)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
    return 0;
}