#include <iostream>
#include <vector>
using namespace std;

// remove all occurrences of val in nums in-place, the order of the elements may be changed, then return the number of elements in nums which are not equal to val
int removeElement(vector<int> &nums, int k){
  int i = 0;
  for(int j = 0; j<nums.size(); j++){
    if(nums[j] != k){
      i++;
      nums[i] = nums[j];
    }
  }
  return i;
}

int main(){
  int n, k;
  cout<<"Enter size: ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter "<<n<<" array elements: ";
  for(int i = 0; i<n; i++)
    cin>>arr[i];
  cout<<"Enter k: ";
  cin>>k;
  cout<<removeElement(arr, k);
  return 0;
}