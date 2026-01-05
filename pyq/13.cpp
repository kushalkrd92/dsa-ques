// print top candidates
#include <bits/stdc++.h>
using namespace std;

int main(){
  int top;    // no of top candidates to be printed
  cin>>top;
  int n;
  cin>>n;
  vector<pair<int, string>> arr(n);  // marks, name
  for(int i = 0; i<n; i++){
    cin>>arr[i].first;
    cin>>arr[i].second;
  }
  sort(arr.begin(), arr.end(), greater<pair<int, string>>());
  for(int i = 0; i<top; i++){
    cout<<arr[i].second<<": "<<arr[i].first<<endl;
  }
  return 0;
}