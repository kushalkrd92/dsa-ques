#include<iostream>

class cats{
    std::string color;
    int age;
    public:
        cats(std::string color){
            this->color = color;
            std::cout<<color<<std::endl;
            // std::cout<<this<<std::endl;
        }
        cats(std::string color, int age){
            this->color = color;
            this->age = age;
            std::cout<<color<<std::endl;
            std::cout<<age<<std::endl;
            // std::cout<<this<<std::endl;
        }
};

int main(){
    cats* luna = new cats("white");
    cats* yoshi = new cats("grey", 3);
    // std::cout<<&luna<<std::endl;
    // std::cout<<&yoshi<<std::endl;
    return 0;
}