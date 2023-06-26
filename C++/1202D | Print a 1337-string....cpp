#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        stack<int> stk;
 
        while(n)
        {
            int add = 1;
            while(n >= add)
            {
                n -= add++;
            }
            stk.push(add);
        }
 
        string s = "13";
        int three = 1;
        while(!stk.empty())
        {
            int u = stk.top();
            stk.pop();
            while(three < u)
            {
                s += '3';
                three++;
            }
            s += '7';
        }
        
        cout << s << endl;
    }
 
    return 0;
}