#include <iostream>
#include <queue>
using namespace std;

int main(){
  // max heap
  priority_queue<int> p;
  p.push(70);
  p.push(60);
  p.push(55);
  p.push(45);
  p.push(50);
  cout<<p.top()<<"\t";
  p.pop();
  cout<<p.top()<<"\t";
  cout<<p.size()<<"\t";
  cout<<p.empty()<<endl;

  // min heap
  priority_queue<int, vector<int>, greater<int>> h;
  h.push(70);
  h.push(60);
  h.push(55);
  h.push(45);
  h.push(50);
  cout<<h.top()<<"\t";
  h.pop();
  cout<<h.top()<<"\t";
  cout<<h.size()<<"\t";
  cout<<h.empty()<<endl;
  return 0;
}