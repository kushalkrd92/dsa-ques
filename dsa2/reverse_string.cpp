#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The input string is given as an array of characters s, in-place
vector<char> reverseString(vector<char> str){
  int i = 0, j = str.size()-1;
  while(i <= j){
    swap(str[i], str[j]);
    i++;
    j--;
  }
  return str;
}

//  reverse the first k characters for every 2k characters counting from the start of the string. If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
string reverseString2(string str, int k){
  int n = str.size();
  for(int i = 0; i<n; i += 2*k){
    if(n >= i+k)                            // only reversing the first k chars
      reverse(str.begin() + i, str.begin() + i + k);
    else                                    // reversing all when fewer than k chars left (i+k > n)
      reverse(str.begin() + i, str.end());
  }
  return str;
}


int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  vector<char> str(n);
  cout<<"Enter string: ";
  for(int i = 0; i<n; i++){
    cin>>str[i];
  }
  vector<char> ans = reverseString(str);
  for(char s: ans)
    cout<<s;

  cout<<endl<<endl;
  string s;
  cout<<"Enter string: ";
  cin>>s;
  string result = reverseString2(s, 2);
  for(char s: result)
    cout<<s;
  return 0;
}