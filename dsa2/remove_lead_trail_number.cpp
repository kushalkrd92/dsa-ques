#include <iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<n<<endl;       // automatically removes leading zeros

  // removing trailing zeros
  while(n%10 == 0)
    n /= 10;
  cout<<n<<endl;
  
  string str = to_string(n);      // int to string
  int num = stoi(str);         // string to int
  return 0;
}