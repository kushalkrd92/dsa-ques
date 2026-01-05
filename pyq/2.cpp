#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  vector<pair<int, string>> students(n);
  for(int i = 0; i<n; i++){
    cin>>students[i].first;
    cin>>students[i].second;
  }

  sort(students.begin(), students.end());
  for(int i = n-1; i >= 0; i--){
    cout<<students[i].second<<": "<<students[i].first<<endl;
  }
  return 0;
}

// sort(nums.begin(), nums.begin()+odd, greater<int>());