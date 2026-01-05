#include<iostream>

void reachHome(int src, int dest){
    if(src == dest)
        return;
    std::cout<<"src: "<<src<<", dest: "<<dest<<std::endl;
    src++;
    reachHome(src, dest);
}

int main(){
    int src = 1, dest = 14;
    reachHome(src, dest);
    std::cout<<"Home reached! ";
    return 0;
}