#include<iostream>

class hero {
    public:
        int level;
        int heart;
        char grade;
        char* grade1;
        char grade2;
        // char grade3;
        // char grade4;
};

int main(){
    hero h1;
    // std::cout<<h1.level<<std::endl;
    // std::cout<<h1.heart<<std::endl;  
    // // std::cout<<h1.grade<<std::endl;    // prints nothing

    // std::cout<<sizeof(h1.heart)<<std::endl;
    // std::cout<<sizeof(h1.level)<<std::endl;
    // std::cout<<sizeof(h1.grade)<<std::endl;
    std::cout<<sizeof(h1)<<std::endl;

    return 0;
}




// padding --
/*
    no data members - size = 1B
    1 data members - size = size of data type (1 for char, 4 for int, 8 for pointers)
    multiple same data type = sum of all sizes
    multiple but different data types = padding gets applied
        2 int, 1 char - size = 2*4 + 4 = 12 
        1 int, 1 pointer - size = ((1*4)+4(padding)) + 8 = 16
        2 int, 1 pointer - size = (2*4 = 8) + 8 = 12 
        1 int, 1 char, 1 pointer - size = 8 + 8 + 8 = 24
        2 int, 1 char, 1 pointer - size = 8 + 8 + 8 = 24
        2 int, 2 char, 1 pointer - size = 8 + 8 + 8 = 24
 */