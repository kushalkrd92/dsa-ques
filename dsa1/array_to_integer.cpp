#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

int toInteger(int arr[], int n){
  int ans = 0;
  for(int i = 0; i<n; i++){
    if(ans < (INT_MIN/10) || ans > (INT_MAX/10))
      return 0;
    ans = ans*10 + arr[i];
  }
  return ans;
}

int main(){
  int n, arr[20];
  cout<<"Enter the size: ";
  cin>>n;
  cout<<"Enter the "<<n<<" array elements: ";
  for(int i = 0; i<n; i++){
    cin>> arr[i];
  }
  cout<<toInteger(arr, n);
  return 0;
}