#include <iostream>
using namespace std;

int main(){
  // char to int
  char c1 = '1', c2 = '9';
  int n1 = c1 - '0';
  int n2 = c2 - '0';
  cout<<n1<<" "<<n2<<endl;

  // int to char
  c1 = n1 + '0';
  c2 = n2 + '0';
  cout<<c1<<" "<<c2<<endl;
  
  // char smaller alphabets to integer index
  char a1 = 'a', a2 = 'z';
  int y1 = a1 - 'a';
  int y2 = a2 - 'a';
  cout<<y1<<" "<<y2<<endl;

  // char capital alphabets to integer index
  char A1 = 'A', A2 = 'Z';
  int Y1 = A1 - 'A';
  int Y2 = A2 - 'A';
  cout<<Y1<<" "<<Y2<<endl;

  // string to integer
  string s = "89";
  int num = stoi(s);
  cout<<num<<endl;

  // integer to string
  num = 987;
  s = to_string(num);
  cout<<s<<endl;

  // to check if a char is digit or not   (for any other symbol returns 0, for digit returns 1)
  char a = 'a', b = '7';
  cout<<isdigit(a)<<" "<<isdigit(b)<<endl;

  // to check if a char is alphabet or not   (for any other symbol returns 0, for alphabet returns +ve integer)
  cout<<isalpha(a)<<" "<<isalpha(b)<<endl;

  // to check if a char is alphabet or numeric or not   (for any other symbol returns 0, for alnum returns +ve integer)
  a = 'b', b = '&';
  cout<<isalnum(a)<<" "<<isalnum(b)<<endl;

  // to uppercase
  a = 'h', b = 's';
  cout<<(char)toupper(a)<<" "<<(char)toupper(b)<<endl;

  // to lowercase
  char c = 'H', d = 'S';
  cout<<(char)tolower(c)<<" "<<(char)tolower(d)<<endl;
  return 0;
}