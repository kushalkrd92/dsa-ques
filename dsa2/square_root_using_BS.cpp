#include <iostream>
#include <math.h>
using namespace std;

int sqrt(int x) {
  if(x <= 1)
    return x;

  int i = 1;
  int j = x;
  while(i <= j){
    int mid = i + (j - i)/2;
    long long square = (long long)mid*mid;
    if(square == x)
      return mid;
    else if(square > x)
      j = mid - 1;
    else 
      i = mid + 1;
  }
  return j;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<sqrt(n)<<endl;
  cout<<pow(n, 0.5)<<endl;
  return 0;
}