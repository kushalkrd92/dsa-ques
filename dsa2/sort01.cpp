#include <iostream>
#include <vector>
using namespace std;

void sort0and1(vector<int> &A){
  int i = 0;
  int j = A.size() - 1;
  while(i <= j){
    if(A[i] == 0)
      i++;
    else if(A[j] == 1)
      j--;
    else if(A[i] == 1 && A[j] == 0){
      swap(A[i], A[j]);
      i++;
      j--;
    }
  }
}

int main(){
  vector<int> arr = {0,1,1,1,0,0,1};
  sort0and1(arr);
  for(int i: arr)
    cout<<i<<" ";
  return 0;
}