#include<iostream>

void sayDigits(int n, std::string arr[]){
    if(n == 0)
        return;
    int digit = n%10;
    n /= 10;
    sayDigits(n, arr);
    std::cout<<arr[digit]<<" ";
}

int main(){
    std::string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n = 179;
    sayDigits(n, arr);
    return 0;
}