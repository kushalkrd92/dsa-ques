#include<iostream>

class Human{
    public:
        int age = 24;
        std::string name = "Ape";
        void eat(){
            std::cout<<"This person can eat"<<std::endl;
        }
};

class Male: public Human{
    public:
        void distinct(){
            std::cout<<"This person is a father"<<std::endl;
        }
};

class Female: public Human{
    public:
        void distinct(){
            std::cout<<"This person is a mother"<<std::endl;
        }
};

class Child: public Male, public Female{
    public:
        void kid(){
            std::cout<<"This person is a kid"<<std::endl;
        }
};

int main(){
    Human h;
    std::cout<<h.age<<std::endl;
    std::cout<<h.name<<std::endl;
    h.eat();

    Male m;
    std::cout<<m.age<<std::endl;
    std::cout<<m.name<<std::endl;
    m.eat();
    m.distinct();

    Female f;
    std::cout<<f.age<<std::endl;
    std::cout<<f.name<<std::endl;
    f.eat();
    f.distinct();

    Child c;
    std::cout<<c.Male::age<<std::endl;
    std::cout<<c.Female::name<<std::endl;
    c.Male::eat();
    c.Female::distinct();
    c.kid();
    return 0;
}