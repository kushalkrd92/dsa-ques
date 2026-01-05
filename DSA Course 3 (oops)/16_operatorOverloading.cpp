#include<iostream>

class Test{
    public:
        int a;
        void operator+ (Test &obj){
            int value1 = this->a;
            int value2 = obj.a;
            std::cout<<value2-value1<<std::endl;
            std::cout<<"Doing some sum"<<std::endl;
        }
        void operator() (){
            std::cout<<"Setting some parenthesis"<<std::endl;
        }
};

int main(){
    Test t1, t2;
    t1.a = 2, t2.a = 4;
    t1 + t2;
    t1();
    return 0;
}