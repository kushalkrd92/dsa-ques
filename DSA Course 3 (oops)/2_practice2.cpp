#include<iostream>
#include "classh.cpp"

int main(){
    hero h2;
    h2.level = 4;
    h2.grade = 'B';
    h2.heart = 11;
    std::cout<<h2.level<<std::endl;
    std::cout<<h2.grade<<std::endl;
    std::cout<<h2.heart<<std::endl;
    return 0;
}