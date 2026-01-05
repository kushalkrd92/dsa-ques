#include <iostream>
#include <vector>
using namespace std;

void swapAlternate(vector<int> &arr){
  for(int i = 0; i<arr.size(); i += 2){
    if(i+1 < arr.size())
      swap(arr[i], arr[i+1]);
  }
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
  swapAlternate(arr);
  for(auto i: arr)
    cout<<i<<" ";
  return 0;
}