#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class MyComp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      if(a.first == b.first)
        return a.second < b.second;      // decreasing order of element
      return a.first > b.first;             // increasing order of freq
    }
};

// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
vector<int> sortArray(vector<int> arr){
  int n = arr.size();
  unordered_map<int, int> mp;   // element, freq
  for(int i: arr)
    mp[i]++;
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, MyComp> pq;     // min heap  // freq, element
  for(auto it = mp.begin(); it != mp.end(); it++)
    pq.push({it->second, it->first});

  vector<int> ans;
  while(!pq.empty()){
    int element = pq.top().second;
    int freq = pq.top().first;
    pq.pop();
    for(int i = 0; i < freq; i++)
      ans.push_back(element);
  }
  return ans;
}

int main(){
  vector<int> arr = {1,1,2,2,2,3,4,4};
  vector<int> ans = sortArray(arr);
  for(int i: ans)
    cout<<i<<" ";
  return 0;
}