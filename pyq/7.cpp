// 5. In a mystical land, a wise sage collects gemstones. Each time he collects a new gemstone, he wonders how many of them are more radiant than any he has collected before. Can you help the sage count these radiant gems?
// Input
// The number of gemstones n.
// The radiance values of the gemstones.
// Output
// The count of gemstones that are more radiant than all previously collected ones.

// Example
// Input:
// 5
// 1 3 2 4 5
// Output:
// 4

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++)
    cin>>arr[i];

  int maxi = INT_MIN;
  int count = 0;
  for(int i: arr){
    if(i > maxi){
      maxi = i;
      count++;
    }
  }
  cout<<count;
  return 0;
}