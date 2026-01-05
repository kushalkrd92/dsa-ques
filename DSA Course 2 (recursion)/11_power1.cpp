#include<iostream>

int power(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    int ans = power(a, b/2);
    if(b%2 == 0)
        return ans*ans;
    else
        return a*ans*ans;
}

int main(){
    int a = 2, b = 11;
    int ans = power(a, b);
    std::cout<<ans;
    return 0;
}