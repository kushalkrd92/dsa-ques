#include<iostream>

bool isSorted(int arr[], int size){
    if(size == 0 || size == 1)
        return true;
    if(arr[0]>arr[1])
        return false;
    else    
        return isSorted(arr+1, size-1);
}

int main(){
    int arr[6] = {2, 6, 7, 11, 23, 25};
    int size = 6;
    if(isSorted(arr, size))
        std::cout<<"Sorted";
    else 
        std::cout<<"Unsortd";
    return 0;
}