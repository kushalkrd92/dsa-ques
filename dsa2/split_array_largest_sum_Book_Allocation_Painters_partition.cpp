#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int k, int mid){
  int count = 1;
  int sum = 0;
  int n = arr.size();
  for(int i = 0; i<n; i++){
    if(sum + arr[i] <= mid)
      sum += arr[i];
    else{
      count++;
      if(count > k || arr[i] > mid)
          return false;
      sum = arr[i];
    }
  }
  return true;
}

// split array largest sum
// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.
int splitArray(vector<int>& nums, int k) {
  int n = nums.size();
  int s = 0;
  int sum = 0;
  for(int num: nums)
    sum += num;
  int e = sum;
  int largestSum = -1;
  if(n < k)
    return largestSum;

  while(s <= e){
    int mid = s + (e-s)/2;
    if(isPossible(nums, k, mid)){
      largestSum = mid;
      e = mid -1;
    }
    else
      s = mid + 1;
  }
  return largestSum;
}

// book allocation problem
// Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
// There are ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible, return -1.
int findPages(vector<int> arr, int m) {
  int n = arr.size();
  if(m > n) 
    return -1; 

  int ans = -1;
	int s = 0, sum = 0;
	for(int i = 0; i<n; i++)
		sum += arr[i];
	int e = sum;
	while(s<=e){
    int mid = s + (e-s)/2;
		if(isPossible(arr, m, mid)){
			ans = mid;
			e = mid - 1;
    } 
		else
			s = mid + 1;
	}
	return ans;
}

// painter's partition problem
// Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.
int findLargestMinDistance(vector<int> &boards, int k){
  int n = boards.size();
  int s = 0;
  int sum = 0;
  for(int i: boards)
    sum += i;
  int e = sum;
  int largestSum = -1;
  if(n < k)
    return largestSum;

  while(s <= e){
    int mid = s + (e-s)/2;
    if(isPossible(boards, k, mid)){
      largestSum = mid;
      e = mid -1;
    }
    else
      s = mid + 1;
  }
  return largestSum;
}

int main(){
  vector<int> arr = {2, 1, 5, 6, 2, 3};
  int k = 2;
  cout<<endl;
  cout<<splitArray(arr, k)<<endl;
  cout<<findPages(arr, k)<<endl;
  cout<<findLargestMinDistance(arr, k)<<endl;
  return 0;
}