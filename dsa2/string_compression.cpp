#include <iostream>
#include <vector>
using namespace std;

// compress such that For each group of 'consecutive repeating characters' in chars: if the group's length is 1, append the character to s. Otherwise, append the character followed by the group's length, in-place
pair<vector<char>, int> stringCompression(vector<char> str){
  int r = 0, w = 0;   // read, write
  int n = str.size();
  while(r < n){
    char ch = str[r];
    int count = 0;
    while(r < n && ch == str[r]){
      count++;
      r++;
    }
    str[w] = ch;
    w++;
    if(count > 1){
      for(char c: to_string(count)){
        str[w] = c;
        w++;
      }
    }
  }
  return {str, w};
}

// same ques, but instead using string
string stringCompression2(string &input) {
    int r = 0, w = 0;   // read, write
    int n = input.size();
    while(r < n){
        char ch = input[r];
        int count = 0;
        while(r < n && ch == input[r]){
            count++;
            r++;
        }
        input[w] = ch;
        w++;
        if(count > 1){
            for(char c: to_string(count)){
                input[w] = c;
                w++;
            }
        }
    }
    input.erase(w, n);
    return input;
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
  pair<vector<char>, int> ans = stringCompression(str);
  cout<<"New Length: "<<ans.second<<endl;
  for(int i = 0; i<ans.second; i++)
    cout<<ans.first[i];
  cout<<endl;
  
  string s = "helloerfdet";
  cout<<stringCompression2(s);
  return 0;
}