#include<iostream>

bool linearSearch(int* arr, int size, int key){
    if(size == 0)
        return false;
    if(key == arr[0])
        return true;
    else
        return linearSearch(arr+1, size-1, key);
}

int main(){
    int arr[6] = {1, 5, 4, 7, 9, 0};
    int size = 6;
    int key = 1;
    if(linearSearch(arr, size, key))
        std::cout<<"present";
    else    
        std::cout<<"absent";
    return 0;
}