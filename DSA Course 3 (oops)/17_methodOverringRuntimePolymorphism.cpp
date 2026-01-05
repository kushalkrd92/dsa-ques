#include<iostream>

class parent{
    private:
        int age;
    public:
        void print(){
            std::cout<<"\nAge is: "<<age<<std::endl;
        }
        void setValue(int age){
            this->age = age;
        }
};

class child: public parent{
    public:
     void print(){
        std::cout<<"Child class function called"<<std::endl;
     }
};

int main(){
    parent p;
    p.setValue(35);
    p.print();
    child c;
    c.print();
    c.setValue(11);
    c.parent::print();
    return 0;
}