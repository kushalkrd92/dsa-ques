#include<iostream>

class hero{
    int health;
    int hearts;
    public:
        hero(int health, int hearts){
            this->health = health;
            this->hearts = hearts;
        }
        void print(){
            std::cout<<"Heart: "<<hearts<<", Health: "<<health<<std::endl;
        }
        ~hero(){
            std::cout<<"destructor called"<<std::endl;
        }
};

int main(){
    hero h1(2, 6);
    h1.print();

    hero* h2 = new hero(5, 10);
    h2->print();
    delete h2;     // for dynamic alloction destructor need to be called manually
    return 0;
}