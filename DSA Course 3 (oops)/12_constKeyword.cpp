#include<iostream>

int main(){
    const int i = 1;   // has to be initialized here
    // i++;     // can't be modified
    std::cout<<i<<std::endl;

    int y = 9;
    const int *z = &y;
    // (*z)++;   // not modifiable
    z++;
    std::cout<<z<<std::endl;
    std::cout<<*z<<std::endl;

    int* const p = &y;
    (*p)++;
    // p++; // not modifiable
    std::cout<<p<<std::endl;
    std::cout<<*p<<std::endl;

    const int* const q = &y;
    // (*q)++;   // not modifiable
    // q++;     // not modifiable
    std::cout<<q<<std::endl;
    std::cout<<*q<<std::endl;
    return 0;
}