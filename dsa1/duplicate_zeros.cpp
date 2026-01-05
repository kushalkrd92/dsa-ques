#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int> &nums){
  int n = nums.size();
  for(int i = 0; i<n; i++){
    if(nums[i] == 0){
      int j = n-1;
      while(i<j){
        nums[j] = nums[j-1];
        j--;
      }
      i++;
    }
  }
}

int main(){
  int n;
  cout<<"Enter size: ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter "<<n<<" array elements: ";
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  duplicateZeros(arr);
  for(int i = 0; i<n; i++)
    cout<<arr[i]<<" ";
  return 0;
}