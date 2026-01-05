// 1. In a bustling chocolate factory, workers are busy packing chocolates into packets. Each packet is represented by an array of integers, where `0` signifies an empty packet. The factory manager has tasked you with finding all the empty packets and pushing them to the end of the array.
// Input format 
// N = 8
// arr = [4, 5, 0, 1, 9, 0, 5, 0]
// Output
// 4 5 1 9 5 0 0 0

#include <bits/stdc++.h>
using namespace std;

vector<int> moveZerosToEnd(vector<int> arr){
  int n = arr.size();
  int nonZeroIndex = 0;
  for(int i = 0; i<n; i++){
    if(arr[i] != 0){
      swap(arr[i], arr[nonZeroIndex]);
      nonZeroIndex++;
    }
  }
  return arr;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }

  // vector<int> arr;
  // string s;
  // getline(cin, s);
  // for(char ch: s){
  //   if(isdigit(ch))
  //     arr.push_back(ch -'0');
  // }
  vector<int> ans = moveZerosToEnd(arr);
  for(int i: ans)
    cout<<i<<" ";
  return 0;
}
