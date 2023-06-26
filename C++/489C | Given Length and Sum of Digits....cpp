#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
bool canMake(int m, int s)
{
    return (s>=0 && s<=9*m);
}
 
int main()
{
    string minNum = "";
    int m, s;
    cin>>m>>s;
    int sum = s;
    if((s==0 && m!=1) || s>9*m)
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int d=0; d<10; d++)
        {
            if((i>1 || d>0 || (m==1 && d==0)) && canMake(m-i,sum-d))
            {
                minNum += char('0'+d);
                sum -= d;
                break;
            }
        }
    }
    cout<<minNum<<' ';
    minNum = "";
    sum = s;
    for(int i=1; i<=m; i++)
    {
        for(int d=9; d>=0; d--)
        {
            if((i>1 || d>0 || (m==1 && d==0)) && canMake(m-i,sum-d))
            {
                minNum += char('0'+d);
                sum -= d;
                break;
            }
        }
    }
    cout<<minNum<<endl;
    return 0;
}