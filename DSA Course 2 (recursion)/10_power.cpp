#include<iostream>

int power(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    return 2*power(a, b-1);
}

int main(){
    int a = 2, b = 8;
    int ans = power(a, b);
    std::cout<<ans;
    return 0;
}