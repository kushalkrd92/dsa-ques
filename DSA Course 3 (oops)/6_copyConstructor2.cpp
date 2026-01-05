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
        dog(dog& temp){
            this->age = temp.age+2;
            this->weight = temp.weight+1;
            this->color = temp.color+"r";
        }
        void print(){
            std::cout<<"Age: "<<age<<"years, weight: "<<weight<<"kg, color: "<<color<<std::endl;
        }
};

int main(){
    dog bob(4, 6, "brown");
    bob.print();
    dog duffy(bob);
    duffy.print();
    return 0;
}