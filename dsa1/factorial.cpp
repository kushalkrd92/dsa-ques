#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

string calculateFactorial(int n){
  string ans = "1";
  int carry = 0;
  for(int i = 2; i <= n; i++){
      for(int j = 0; j < ans.size(); j++){
          int num = (ans[j] - '0')*i + carry;
          ans[j] = (num%10 + '0');
          carry = num/10;
      }
      while(carry){
          ans += (carry%10 + '0');
          carry /= 10;
      }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

// integer output
int calculateFactorial2(int n){
  string ans = "1";
  int carry = 0;
  for(int i = 2; i <= n; i++){
      for(int j = 0; j < ans.size(); j++){
          int num = (ans[j] - '0')*i + carry;
          ans[j] = (num%10 + '0');
          carry = num/10;
      }
      while(carry){
          ans += (carry%10 + '0');
          carry /= 10;
      }
  }
  reverse(ans.begin(), ans.end());

  int result = 0;
  for(int i = 0; i<ans.size(); i++)
    result = result*10 + (ans[i] - '0');
  return result;
}

// integer output MOD
int calculateFactorial3(int n){
  string ans = "1";
  int carry = 0;
  for(int i = 2; i <= n; i++){
      for(int j = 0; j < ans.size(); j++){
          int num = (ans[j] - '0')*i + carry;
          ans[j] = (num%10 + '0');
          carry = num/10;
      }
      while(carry){
          ans += (carry%10 + '0');
          carry /= 10;
      }
  }
  reverse(ans.begin(), ans.end());

  int result = 0;
  for(int i = 0; i<ans.size(); i++)
    result = result*10 + (ans[i] - '0');
  return result%MOD;
}

// string output, trailing zeros removed
string calculateFactorial4(int n){
  string ans = "1";
  int carry = 0;
  for(int i = 2; i <= n; i++){
      for(int j = 0; j < ans.size(); j++){
          int num = (ans[j] - '0')*i + carry;
          ans[j] = (num%10 + '0');
          carry = num/10;
      }
      while(carry){
          ans += (carry%10 + '0');
          carry /= 10;
      }
  }
  reverse(ans.begin(), ans.end());
  int i = ans.size() - 1;
  while(ans[i] == '0' && i >= 0)
    i--;
  ans = ans.substr(0, i+1);
  return ans;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<calculateFactorial(n)<<endl;
  cout<<calculateFactorial2(n)<<endl;
  cout<<calculateFactorial3(n)<<endl;
  cout<<calculateFactorial4(n)<<endl;
  return 0;
}