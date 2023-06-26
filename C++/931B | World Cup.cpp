#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
class Tournament {
    int final;
public:
    Tournament(int n)
    {
        final = 0;
        while((n>>final) != 1)
        {
            final++;
        }
        //cout<<final<<endl;
    }
    void meet(int a, int b)
    {
        int stage = 1;
        int teamA = (a+1)/2;
        int teamB = (b+1)/2;
        while(teamA != teamB)
        {
            teamA = (teamA+1)/2;
            teamB = (teamB+1)/2;
            stage++;
        }
        if(stage == final)
            cout<<"Final!"<<endl;
        else
            cout<<stage<<endl;
    }
};
 
int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    Tournament tour(n);
    tour.meet(a,b);
    return 0;
}