#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){
  // unordered map
  unordered_map<string, int> m;

  // insertion 
  pair<string, int> p = make_pair("Apple", 3);      // #1
  m.insert(p);
  pair<string, int> p2("Cherry", 2);                // #2
  m.insert(p2);     
  m["Guava"] = 1;                                   // #3
  m["Guava"] = 2;      // updation

  // searching
  cout<<m["Apple"]<<endl;
  cout<<m.at("Cherry")<<endl;

  cout<<m["Pineapple"]<<endl;         // new key created
  cout<<m.at("Pineapple")<<endl;

  // size
  cout<<m.size()<<endl;

  // check if key present or not
  cout<<m.count("Apple")<<endl;
  cout<<m.count("Banana")<<endl;

  // delete key
  m.erase("Pineapple");
  cout<<m.size()<<endl;

  // iterator - unordered map prints not in order
  // #1
  for(auto i: m){
    cout<<i.first<<" "<<i.second<<endl;
  }
  cout<<endl;
  // #2
  unordered_map<string, int> :: iterator it = m.begin();
  while(it != m.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
  }

  // map 
  map<string, int> m1;
  for(auto i: m){
    m1.insert(i);
  }
  cout<<endl;
  // iterator - map prints in order
  map<string, int> :: iterator it1 = m1.begin();
  while(it1 != m1.end()){
    cout<<it1->first<<" "<<it1->second<<endl;
    it1++;
  }

  return 0;
}
