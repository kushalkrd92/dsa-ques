#include <iostream>
#include <vector>
using namespace std;

// using Binary Search
// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.
bool searchMatrix(vector<vector<int>> arr, int k){
  int r = arr.size();
  int c = arr[0].size();
  int i = 0, j = r*c - 1;
  while(i <= j){
    int mid = i + (j - i)/2;
    int element = arr[mid/c][mid%c];
    if(element == k)
      return true;
    else if (element > k)
      j = mid - 1;
    else  
      i = mid + 1;
  }
  return false;
}

// return indexes
pair<int, int> searchMatrix2(vector<vector<int>> arr, int k){
  int r = arr.size();
  int c = arr[0].size();
  int i = 0, j = r*c - 1;
  while(i <= j){
    int mid = i + (j - i)/2;
    int element = arr[mid/c][mid%c];
    if(element == k)
      return {mid/c, mid%c};
    else if (element > k)
      j = mid - 1;
    else  
      i = mid + 1;
  }
  return {-1, -1};
}

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// The first integer of each row may not be greater than the last integer of the previous row.
bool searchMatrix3(vector<vector<int>>& matrix, int target) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  int rowIndex = 0;
  int colIndex = cols-1;
  while(rowIndex < rows && colIndex >= 0){
    int element = matrix[rowIndex][colIndex];
    if(element == target)
      return true;
    else if(element > target)
      colIndex--;
    else
      rowIndex++;
  }
  return 0;
}

int main(){
  vector<vector<int>> arr = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  int k = 60;
  cout<<searchMatrix(arr, k)<<endl;
  pair<int, int> p = searchMatrix2(arr, k);
  cout<<p.first<<" "<<p.second<<endl;

  vector<vector<int>> arr1 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  k = 23;
  cout<<searchMatrix3(arr1, k)<<endl;
  return 0;
}