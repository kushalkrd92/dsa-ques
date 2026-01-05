#include <iostream>
#include <vector>
#include <map>
using namespace std;

// always use map for using greater<int> for decreasing order or by default increasing order sorting based on the key unordered_map will not work

// For each index i, names[i] and heights[i] denote the name and height of the ith person.
// Return names sorted in descending order by the people's heights.
vector<string> sortPeople(vector<string> names, vector<int> heights){
  int n = names.size();
  map<int, string, greater<int>> mp;     // height, name -> decending order of height   
  for(int i = 0; i<n; i++)
    mp[heights[i]] = names[i];
  
  vector<string> ans;
  for(auto i: mp)
    ans.push_back(i.second);
  return ans;
}

int main(){
  vector<string> names = {"Mary","John","Emma"};
  vector<int> heights = {180,165,170};
  for(auto i: sortPeople(names, heights))
    cout<<i<<" ";
  return 0;
}