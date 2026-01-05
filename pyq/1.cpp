#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> arr = {3, 5, 6, 8, 10, 15, 4, 1, 30};
  for(int i = 0; i<arr.size(); i++){
    if(arr[i]%3 == 0 && arr[i]%5 == 0)
      cout<<"ThreeFive ";
    else if(arr[i]%3 == 0)
      cout<<"Three ";
    else if(arr[i]%5 == 0)
      cout<<"Five ";
    else  
      cout<<arr[i]<<" ";
  }
  return 0;
}