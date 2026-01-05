#include <iostream>
using namespace std;

// Choose a star in s, Remove the closest non-star character to its left, as well as remove the star itself.
string removeStars(string str){
  int i = 0;
  for(int j = 0; j<str.size(); j++){
    if(str[j] == '*')
      i--;
    else {
      str[i] = str[j];
      i++;
    }
  }
  return str.substr(0, i);
}

int main(){
  string str;
  cout<<"Enter string: ";
  cin>>str;
  cout<<removeStars(str);
  return 0;
}