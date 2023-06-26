#include <iostream>
#include <map>
using namespace std;
 
int main()
{
   int ipNo, cmdNo;
   string name, ip, command;
   map <string, string> ipList;
   cin>>ipNo>>cmdNo;
   for(int i=0; i<ipNo; i++)
   {
      cin>>name>>ip;
      ip += ";";
      ipList[ip] = name;
   }
   for(int i=0; i<cmdNo; i++)
   {
      cin>>command>>ip;
      cout<<command<<" "<<ip<<" #"<<ipList[ip]<<"\n";
   }
   return 0;
}