#include <iostream>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    int freq1[26] = {0};
    int freq2[26] = {0};
    int i = 0;
    while (input1[i] != '\0'){
        freq1[input1[i] - 'a']++;
        i++;
    }
    i = 0;
    while(input2[i] != '\0'){ 
        freq2[input2[i] - 'a']++;
        i++;
    }
    for(int i = 0; i<26; i++){
        if(freq1[i] != freq2[i]) 
            return false;
    }
    return true;
}

int main(){
  char s[20], t[20];
  cout<<"Enter two words: ";
  cin>>s>>t;
  cout<<isPermutation(s, t);
  return 0;
}