#include <iostream>
using namespace std;

bool palindrome(int n){
  if(n < 0)
    return false;
  
  int num = n;
  int rev = 0;
  while(num){
    int rem = num%10;
    rev = 1LL*rev*10 + rem;
    num /= 10;
  }
  return n == rev;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<palindrome(n);
  return 0;
}