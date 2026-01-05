// default copy constructor
#include<iostream>

class dog{
    int age;
    std::string color;
    int weight;
    public:
        dog(int age, int weight, std::string color){
            this->age = age;
            this->weight = weight;
            this->color = color;
        }
        void print(){
            std::cout<<"Age: "<<age<<", weight: "<<weight<<", color: "<<color<<std::endl;
        }
};

int main(){
    dog bob(4, 6, "brown");
    bob.print();
    dog duffy(bob);
    duffy.print();
    dog pluto = duffy;   // copy assignment operator
    pluto.print();
    return 0;
}