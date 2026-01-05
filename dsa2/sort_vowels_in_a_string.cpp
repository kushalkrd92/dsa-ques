#include <iostream>
#include <algorithm>
using namespace std;

void sortVowels(string &str){
  string temp;
  int n = str.size();
  for(int i = 0; i<n; i++){
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||str[i] == 'u' || str[i] == 'A' ||str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
      temp.push_back(str[i]);
  }
  sort(temp.begin(), temp.end());

  int j = 0;
  for(int i = 0; i<n; i++){
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||str[i] == 'u' || str[i] == 'A' ||str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
      str[i] = temp[j];
      j++;
    }
  }
}

int main(){
  string str;
  cout<<"Enter string: ";
  cin>>str;
  sortVowels(str);
  cout<<str;
  return 0;
}