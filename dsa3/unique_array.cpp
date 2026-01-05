#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// all elements are unique or not
bool isUnique(vector<int> v){
  unordered_map<int, int> mp;    // element, freq
  for(int i = 0; i<v.size(); i++){
    mp[v[i]]++;
  }
  for(auto i: mp){
    if(i.second > 1)
      return false;
  }
  return true;
}

// sum of all unique elements
int sumUnique(vector<int> v){
  unordered_map<int, int> mp;    // element, freq
  int count = 0;
  for(int i = 0; i<v.size(); i++){
    mp[v[i]]++;
  }
  for(auto i: mp){
    if(i.second == 1)
      count++;
  }
  return count;;
}

// number of occurrences of each element
void occurrence(vector<int> v){
  unordered_map<int, int> mp;    // element, freq
  for(int i = 0; i<v.size(); i++){
    mp[v[i]]++;
  }
  
  for(auto i: mp){                    // in reverse order
    cout<<i.first<<" -> "<<i.second<<endl;
  }
  cout<<endl;

  for(int i = 0; i<mp.size(); i++){    // in correct order
    cout<<i<<" -> "<<mp[i]<<endl;
  }
}

// find if all the occurrences of each element are unique or not
bool uniqueOccurrence(vector<int> v){
  unordered_map<int, int> mp;
  for(auto i: v)
    mp[i]++;
  
  set<int> s;
  for(auto i: mp)
    s.insert(i.second);
  return mp.size() == s.size();
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter "<<n<<" array elemnets: ";
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  cout<<"Is unique: "<<isUnique(arr)<<endl;
  cout<<"Sum of unique elements: "<<sumUnique(arr)<<endl;
  occurrence(arr);
  cout<<"Unique Occurrence: "<<uniqueOccurrence(arr);
  return 0;
}