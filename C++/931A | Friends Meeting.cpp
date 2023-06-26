#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
class Meeting {
    int a, b;
    int tire(int n)
    {
        return (n*(n+1))/2;
    }
public:
    int minTire()
    {
        int meet = (a+b)/2;
        return tire(abs(meet-a)) + tire(abs(meet-b));
    }
    friend istream& operator>>(istream&, Meeting&);
};
 
istream& operator>>(istream& stream, Meeting& obj)
{
    stream>>obj.a>>obj.b;
    return stream;
}
 
int main()
{
    Meeting meeting;
    cin>>meeting;
    cout<<meeting.minTire()<<endl;
    return 0;
}