#include <iostream>
using namespace std;

int* reverse(int* arr, int n){
  int i = 0, j = n-1;
  while(i <= j){
    // int temp = arr[i];
    // arr[i] = arr[j];
    // arr[j] = temp;
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
  return arr;
} 

int main(){
  int n, arr[20];
  cout<<"Enter n: ";
  cin>>n;
  cout<<"Enter the "<<n<<" array elements: ";
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  reverse(arr, n);
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}