#include<iostream>
#include<string.h>

class dog{
    public:
        char* color;
        dog(char* color){
            this->color = color;
        }
        dog(dog& temp){
            char*ch = new char(strlen(temp.color)+1);
            strcpy(ch, temp.color);
            this->color = temp.color;
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