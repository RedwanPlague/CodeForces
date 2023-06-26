#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
vector<string> cmd;
 
class Puzzle
{
 vector<string> grid;
 
public:
 
 Puzzle()
 {
  grid.resize(6);
 }
 
 friend istream& operator >> (istream &in, Puzzle &puzzle) 
 {
  for(int i=0; i<6; i++)
   in >> puzzle.grid[i];
  return in;
 }
 
 friend ostream& operator << (ostream &out, const Puzzle &puzzle) 
 {
  cout << "------" << endl;
  for(int i=0; i<6; i++)
   out << puzzle.grid[i] << endl;
  cout << "------" << endl;
  return out;
 }
 
 void find(char ch, int &r, int &c)
 {
  for(r=0; r<6; r++)
   for(c=0; c<6; c++)
    if(grid[r][c] == ch)
     return;
 }
 
 void move(char dir, int id)
 {
  string s = "";
  s += dir;
  s += (char)(id+'1');
  cmd.push_back(s);
  if(dir == 'L')
  {
   for(int j=0; j<5; j++)
    swap(grid[id][j], grid[id][j+1]);
  }
  else if(dir == 'R')
  {
   for(int j=5; j>0; j--)
    swap(grid[id][j], grid[id][j-1]);
  }
  else if(dir == 'U')
  {
   for(int i=0; i<5; i++)
    swap(grid[i][id], grid[i+1][id]);
  }
  else if(dir == 'D')
  {
   for(int i=5; i>0; i--)
    swap(grid[i][id], grid[i-1][id]);
  }
 }
 
 void move(char dir, int &r, int &c)
 {
  if(dir == 'R')
  {
   move('D',c); move('L',r); move('D',c); move('R',r);
   move('D',c); move('L',r); move('D',c); move('R',r);
   move('D',c); move('L',r); move('D',c); move('R',r);
   move('D',c);
   c = (c+1)%6;
  }
  else if(dir == 'L')
  {
   move('D',c); move('R',r); move('D',c); move('L',r);
   move('D',c); move('R',r); move('D',c); move('L',r);
   move('D',c); move('R',r); move('D',c); move('L',r);
   move('D',c);
   c = (c+5)%6;
  }
  else if(dir == 'U')
  {
   move('L',r); move('D',c); move('L',r); move('U',c);
   move('L',r); move('D',c); move('L',r); move('U',c);
   move('L',r); move('D',c); move('L',r); move('U',c);
   move('L',r);
   r = (r+5)%6;
  }
  else if(dir == 'D')
  {
   move('L',r); move('U',c); move('L',r); move('D',c);
   move('L',r); move('U',c); move('L',r); move('D',c);
   move('L',r); move('U',c); move('L',r); move('D',c);
   move('L',r);
   r = (r+1)%6;
  }
 }
};
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
 Puzzle puzzle;
 cin >> puzzle;
 string order = "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210";
 int gr = 5, gc= 5;
 for(int i=0; i<36; i++)
 {
  int r, c;
  puzzle.find(order[i],r,c);
 
  while(c < gc)
   puzzle.move('R',r,c);
  while(c > gc)
   puzzle.move('L',r,c);
  while(r < gr)
   puzzle.move('D',r,c);
 
  gc--;
  if(gc < 0)
  {
   gc = 5;
   gr--;
  }
 }
 
 cout << cmd.size() << '\n';
 for(auto s: cmd)
  cout << s << '\n';
 
 // cout << puzzle;
 
 return 0;
}