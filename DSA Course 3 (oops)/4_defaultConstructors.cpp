#include <iostream>

class vehicle{
    private:
        int price;
        std::string color;
    public:
        void setValues(int p, std::string c){
            price = p;
            color = c;
        }
        void getValues(){
            std::cout<<price<<std::endl;
            std::cout<<color<<std::endl;
        }
        vehicle(){
            setValues(110000000, "Red");
            getValues();
        }
};

int main(){
    // vehicle car;
    vehicle car();

    // vehicle* bike = new vehicle;
    vehicle* bike = new vehicle();

    return 0;
}