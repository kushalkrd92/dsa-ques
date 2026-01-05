#include<iostream>

void reverse(std::string& str, int i, int j){
	if(i>j)
		return;
	std::swap(str[i++], str[j--]);
	reverse(str, i, j);
}

int main(){
    std::string str = "abcdef";
    int s = 0;
    int e = str.length()-1;
    reverse(str, s, e);
    std::cout<<str;
    return 0;
}