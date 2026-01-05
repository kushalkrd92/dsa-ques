// replace by Three, Five, ThreeFive
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; 
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  for(int i = 0; i<n; i++){
    if(arr[i]%3 == 0 && arr[i]%5 == 0)
      cout<<"ThreeFive ";
    else if(arr[i]%3 == 0)
      cout<<"Three ";
    else if(arr[i]%5 == 0)
      cout<<"Five ";
    else
      cout<<arr[i]<<" ";
  }
  return 0;
}