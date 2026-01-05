#include<iostream>

class calc{
    int a;
    int b;
    public:
        calc(int i, int j): a(i), b(j) {
            std::cout<<a+b<<std::endl;
        }
};

class sci{
    int a;
    int b;
    public:
        sci(int, int);
};
sci::sci(int i, int j){
    a = i, b = j;
    std::cout<<a%b<<std::endl;  
}

class sci1: public sci{
    int a;
    int b;
    public:
        sci1(int, int);
};
sci1::sci1(int i, int j): sci(i, j) {
    a = i, b = j;
    std::cout<<a/b<<std::endl;  
}

int main(){
    calc c(2, 4);
    sci1(7, 5);
    return 0;
}