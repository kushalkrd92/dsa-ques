#include<iostream>

bool binarySearch(int* arr, int s, int e, int key){
    if(s>e)
        return false;
    int mid = s + (e-s)/2;
    if(arr[mid] == key)
        return true;
    else if(arr[mid] > key)
        return binarySearch(arr, s, mid-1, key);
    else
        return binarySearch(arr, mid+1, e, key);
}

int main(){
    int arr[6] = {2, 5, 7, 9, 11, 44};
    int s = 0, e = 5, key = 21;
    if(binarySearch(arr, s, e, key))
        std::cout<<"present";
    else 
        std::cout<<"absent";
    return 0;
}