#include<iostream>

class cloth{
    std::string type;
    std::string color;
    static int price;
    public:
        static void fun(){
            std::cout<<price<<std::endl;
        }
        void setValues(std::string type, std::string color){
            this->type = type;
            this->color = color;
        }
        void printValues(){
            std::cout<<"Type: "<<type<<", Color: "<<color<<", Price: "<<price<<std::endl;
        }
};
int cloth::price = 11000;

int main(){
    cloth::fun();
    cloth c1;
    c1.fun();     //not recommended
    c1.setValues("Jeans", "Black");
    c1.printValues();
    return 0;
}