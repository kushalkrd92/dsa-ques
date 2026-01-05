#include<iostream>

class food{
    int amount;
    int price;
    std::string name;
    public:
        const void setAmount(int amount){
            this->amount = amount;
        }
        void getAmount(){
            std::cout<<amount<<std::endl;
        }

        int setPrice(int price) const{
            // this->price = price;
            return price;
        }
        void getPrice(){
            std::cout<<price<<std::endl;
        }

        const std::string setName(const std::string n){
            name = n;
            return name;
        }
};

int main(){
    food f1;
    f1.setAmount(2200);
    f1.getAmount();
    f1.setPrice(220);
    f1.getPrice();

    const food f2();   // () has to be here
    // f2.setAmount(222);
    // f2.getAmount();
    // f2.setPrice(22);
    // std::string str = f2.setName("Fast Food");

    std::string str = f1.setName("Fast Food");
    std::cout<<str<<std::endl;

    return 0;
}