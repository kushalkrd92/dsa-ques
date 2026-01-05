#include <iostream>
#include <vector>
using namespace std;

int fiboSum(int n , int m)
{
  int sum = 0;
  int prev1 = 1;
  int prev2 = 0;
  
  if(n < 2)
    sum = 1;

  for(int i = 2; i <= m; i++){
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
    if(n <= i)
      sum = sum + prev1;
  }
  return sum;
}

int main(){
  int n, m;
  cout<<"Enter range of terms: ";
  cin>>n>>m;
  cout<<fiboSum(n, m);
}