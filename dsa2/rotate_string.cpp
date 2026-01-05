#include <iostream>
using namespace std;

bool rotateString(string s, string goal) {
  if(s.size() != goal.size())
    return false;
  string check = s+s;
  return check.find(goal) != string::npos;
}

int main(){
  string s = "abcde", goal = "cdeab";
  cout<<rotateString(s, goal);
  return 0;
}