#include <iostream>
#include <utility>    // pair
#include <limits.h>
using namespace std;

pair<int, int> maxMin(int arr[], int n){
  pair<int, int> ans;
  int maxi = INT_MIN, mini = INT_MAX;
  for(int i = 0; i<n; i++){
    // if(arr[i] < mini)
    //   mini = arr[i];
    // if(arr[i] > maxi)
    //   maxi = arr[i];
    maxi = max(maxi, arr[i]);
    mini = min(mini, arr[i]);
  }
  ans.first = maxi;
  ans.second = mini;
  return ans;
}

int main(){
  int n, arr[20];
  cout<<"Enter size: ";
  cin>>n;
  cout<<"Enter the "<<n<<" array elements: ";
  for(int i = 0; i<n; i++)
    cin>>arr[i];
  pair<int, int> result = maxMin(arr, n);
  cout<<result.first<<" "<<result.second<<endl;
  return 0;
}