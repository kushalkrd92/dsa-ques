#include<iostream>

class Hero{
    public:
        int health;
        int heart;
        std::string name;
};

int main(){
    Hero h1;    // static
    Hero* h2 = new Hero;    //dynamic

    (*h2).health = 11;
    h2->heart = 5;
    h2->name = "steve";

    std::cout<<h2->health<<std::endl;
    std::cout<<h2->heart<<std::endl;
    std::cout<<(*h2).name<<std::endl;

    std::cout<<sizeof(h1)<<std::endl;
    std::cout<<sizeof(h2)<<std::endl;    // size of pointer
    std::cout<<sizeof(*h2)<<std::endl;
    return 0;
}