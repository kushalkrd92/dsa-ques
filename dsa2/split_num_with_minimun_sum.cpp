#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a positive integer num, split it into two non-negative integers num1 and num2 such that:
// The concatenation of num1 and num2 is a permutation of num.
// In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num. num1 and num2 can contain leading zeros. Return the minimum possible sum of num1 and num2.
// Notes:
// It is guaranteed that num does not contain any leading zeros.
// The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.
int splitNum(int n){
  vector<int> digits;
  while(n){
    digits.push_back(n % 10);
    n /= 10;
  }
  sort(digits.begin(), digits.end());
  long long num1 = 0, num2 = 0;
  for(int i = 0; i<digits.size(); i++){
    if(i%2 == 0)
      num1 = num1 * 10 + digits[i];
    else
      num2 = num2 * 10 + digits[i];
  }
  return num1 + num2;
}

int main(){
  int n = 687;
  cout<<splitNum(n);
}