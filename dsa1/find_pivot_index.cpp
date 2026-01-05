#include <iostream>
#include <vector>
using namespace std;

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// Return the leftmost pivot index. If no such index exists, return -1.
// OR Find the Middle Index in Array; leftmost middle index       <---******
int pivotIndex(vector<int> arr){
  int n = arr.size();
  int totalSum = 0, leftSum = 0;
  for(int i: arr)
    totalSum += i;
  
  for(int i = 0; i<n; i++){
    int rightSum = totalSum - leftSum - arr[i];
    if(leftSum == rightSum)
      return i;
    leftSum += arr[i];
  }
  return -1;
}

// find the pivot integer x such that: The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Return the pivot integer x. If no such integer exists, return -1
int pivotInteger(int n) {
  int totalSum = 0, leftSum = 0;
  for(int i = 1; i <= n; i++) 
    totalSum += i;

  for(int i = 1; i <= n; i++){
    int rightSum = totalSum - leftSum - i;
    if(leftSum == rightSum) 
        return i;
    leftSum += i;
  }
  return -1;
}

int main(){
  vector<int> arr = {1,7,3,6,5,6};
  cout<<pivotIndex(arr)<<endl;
  int n = 8;
  cout<<pivotInteger(n);
  return 0;
}