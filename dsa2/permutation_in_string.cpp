#include <iostream>
using namespace std;

bool checkEqual(int a[26], int b[26]){
  for(int i = 0; i<26; i++){
    if(a[i] != b[i])
      return 0;
  }
  return 1;
}

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
bool checkInclusion(string s1, string s2) {
  int count1[26] = {0};
  for(int i = 0; i<s1.length(); i++){
    int index = s1[i] - 'a';
    count1[index]++;
  }

  int windowSize = s1.length();
  int count2[26] = {0};
  int i = 0;
  while(i<windowSize && i<s2.length()){     // first window
    int index = s2[i] - 'a';
    count2[index]++;
    i++;
  }
  if(checkEqual(count1, count2))
    return 1;

  while(i<s2.length()){        // next window
    char newChar = s2[i];
    int index = newChar - 'a';
    count2[index]++;
    char oldChar = s2[i-windowSize];
    index = oldChar - 'a';
    count2[index]--;
    i++;
    if(checkEqual(count1, count2))
      return 1;
  }
  return 0;
}

int main(){
  string s1 = "ab", s2 = "ghybamu";
  cout<<checkInclusion(s1, s2);
  return 0;
}