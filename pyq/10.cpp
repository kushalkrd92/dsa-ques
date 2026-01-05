// sum of unique elements
#include <bits/stdc++.h>
using namespace std;

int uniqueElements(vector<int> arr){
  unordered_map<int, int> mp; // element, freq
  int sum = 0;
  for(int i: arr)
    mp[i]++;
  for(auto i: mp){
    if(i.second == 1)
      sum += i.first;
  }
  return sum;
}

int main(){
  vector<int> arr = {1, 2, 3, 2};
  cout<<uniqueElements(arr);
  return 0;
}