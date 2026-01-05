#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int k){
  for(int i = 0; i<n; i++){
    if(arr[i] == k)
      return i;
  }
  return -1;
} 

int main(){
  int n, arr[20];
  cout<<"Enter n: ";
  cin>>n;
  cout<<"Enter the "<<n<<" array elements: ";
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  int k;
  cout<<"Enter the key: ";
  cin>>k;
  cout<<linearSearch(arr, n, k);
  return 0;
}