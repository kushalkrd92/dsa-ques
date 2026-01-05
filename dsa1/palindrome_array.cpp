#include <iostream>
#include <vector>
using namespace std;

bool checkPalindrome(vector<int> arr){
  int i = 0; 
  int j = arr.size() - 1;
  while(i <= j){
    if(arr[i] != arr[j])
      return false;
    i++;
    j--;
  }
  return true;
}

bool checkPalindrome2(int arr[], int n){
  int i = 0; 
  int j = n - 1;
  while(i <= j){
    if(arr[i] != arr[j])
      return false;
    i++;
    j--;
  }
  return true;
}

int main(){
  int arr[] = {0, 1, 2, 1, 0};
  vector<int> arr1 = {1, 1, 2, 1, 1};
  cout<<checkPalindrome(arr1)<<endl;
  cout<<checkPalindrome2(arr, 5)<<endl;
}