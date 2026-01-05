#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int>& arr){
  int zeros = 0, ones = 0,twos = 0;
  for(int i=0;i<arr.size();i++){
    if(arr[i] == 0)
      zeros++;
    else if(arr[i] == 1)
      ones++;
    else if(arr[i] == 2)
      twos++;
  }

  for(int i=0; i<arr.size(); i++){
    if(zeros != 0){
      arr[i]=0;
      zeros--;
    }
    else if(ones != 0 && zeros == 0){
      arr[i]=1;
      ones--;
    }
    else if(twos != 0 && ones == 0 && zeros == 0){
      arr[i]=2;
      twos--;
    }
  }
}

int main(){
  vector<int> arr = {2, 2, 2, 2, 0, 0, 1, 0};
  sortArray(arr);
  for(int i: arr)
    cout<<i<<" ";
  return 0;
}