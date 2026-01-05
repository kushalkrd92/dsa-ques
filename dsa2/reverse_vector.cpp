#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &arr){
  int i = 0;
  int j = arr.size() - 1;
  while(i <= j){
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter the "<<n<<" array elements: ";
  for(int i = 0; i<n; i++)
    cin>>arr[i];

  reverse(arr);
  cout<<arr.front()<<" "<<arr.back()<<endl;
  for(int i: arr)
    cout<<i<<" ";
}