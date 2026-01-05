#include <iostream>
using namespace std;

// Coprime numbers are two or more numbers that share only one common factor, which is 1
// if GCD of two Number is 1 then they are coprime else they are not coprime
bool checkCoPrime(long a, long b){
  while(a != b){
    if(a > b)
      a = a - b;
    else
      b = b - a;
  }
  long gcd = a;
  if(gcd == 1)
    return true;
  return false;
}

int main(){
  int n, m;
  cout<<"Enter two numbers: ";
  cin>>n>>m;
  cout<<checkCoPrime(n, m);
  return 0;
}