#include<iostream>

class Animal{
    protected:
        int age = 3;
    public:
        void eat(){
            std::cout<<"This animal can eat"<<std::endl;
        }
};

class Dog: public Animal{
    private:
        std::string breed =  "chhuuachuaa";
    public:
        void bark(){
            std::cout<<"Dog is barking"<<std::endl;
        }
};

int main(){
    Animal a;
    // a.age = 11;
    Dog nikki;
    // nikki.breed = "chhuuachuaa";
    nikki.bark();
    // nikki.age;
    nikki.eat();

    return 0;
}