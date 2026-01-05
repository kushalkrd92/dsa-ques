// default copy constructor
#include<iostream>

class dog{
    public:
        char* color;
        dog(char* color){
            this->color = color;
        }
        void print(){
            std::cout<<"color: "<<color<<std::endl;
        }
};

int main(){
    char ch[] = "brown";
    dog bob(ch);
    bob.print();
    dog duffy(bob);
    bob.color[0] = 'g';
    bob.print();
    duffy.print();

    return 0;
}