#include <iostream>
using namespace std;
 
int main()
{
    int a, b, c;
    bool ans = false;
    cin>>a>>b>>c;
    
    if(a==1 || b==1 || c==1)
        ans = true;
    if(a==3 && b==3 && c==3)
        ans = true;
    if((a==2 && b==2) || (a==2 && c==2) || (b==2 && c==2))
        ans = true;
    if(a%2==0 && b%2==0 && c%2==0 && a+b+c==10)
        ans = true;
    
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}