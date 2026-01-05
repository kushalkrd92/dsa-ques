#include<iostream>

class Test{
    public:
    int i = 1;
        void fun(){
            std::cout<<i++<<std::endl;
        }
        void fun(int a){
            std::cout<<i++<<std::endl;
        }
        void fun(int a, int b){
            std::cout<<i++<<std::endl;
        }
        void fun(int a, char b){
            std::cout<<i++<<std::endl;
        }
        // int fun(){
        //     std::cout<<i++<<std::endl;
        //     return 1;
        // }

        // using default argument
        int add(int a, int b, int c = 0, int d = 0){
            return a+b+c+d;
        }
};

int main(){
    Test t1;
    t1.fun();
    t1.fun(1);
    t1.fun(1, 2);
    t1.fun(2, 'c');
    std::cout<<t1.add(1, 2)<<std::endl;
    std::cout<<t1.add(1, 2, 3)<<std::endl;
    std::cout<<t1.add(1, 2, 3, 4)<<std::endl;

    return 0;
}