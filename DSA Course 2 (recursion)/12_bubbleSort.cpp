#include<iostream>
#include<vector>

void bubbleSort(std::vector<int>& arr, int n)
{   
    if(n == 0 || n == 1)
        return;

    for(int i = 0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            std::swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, n-1);
}

int main(){
    std::vector<int> arr;
    arr.push_back(11);
    arr.push_back(45);
    arr.push_back(1);
    arr.push_back(71);
    arr.push_back(21);
    int n = 5;
    bubbleSort(arr, n);
    for(int i = 0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}