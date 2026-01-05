#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// two numbers are given in form of vectors, sum them then return in form of vector
vector<int> sumNumbers(vector<int> num1, vector<int> num2){
  int n = num1.size(), m = num2.size();
  int i = n-1, j = m-1;
  int carry = 0;
  vector<int> ans;
  while(i >= 0 && j >= 0){
    int sum = num1[i] + num2[j] + carry;
    sum %= 10;
    ans.push_back(sum);
    carry = sum/10; 
    i--;
    j--;
  }
  while(i >= 0){
    int sum = num1[i] + carry;
    sum %= 10;
    ans.push_back(sum);
    carry = sum/10;
    i--;
  }
  while(j >= 0){
    int sum = num2[j] + carry;
    sum %= 10;
    ans.push_back(sum);
    carry = sum/10;
    j--;
  }
  while(carry){
    ans.push_back(carry%10);
    carry /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  vector<int> num1 = {1, 2, 3, 4};
  vector<int> num2 = {1, 2, 3};
  vector<int> ans = sumNumbers(num1, num2);
  for(int i: ans)
    cout<<i;
  return 0;
}
