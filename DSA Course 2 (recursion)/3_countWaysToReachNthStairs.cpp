#include<iostream>

int reachStairs(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    return reachStairs(n-1) + reachStairs(n-2);
}

int main(){
    int n = 9;
    int ways = reachStairs(n);
    std::cout<<ways<<std::endl;
    return 0;
}