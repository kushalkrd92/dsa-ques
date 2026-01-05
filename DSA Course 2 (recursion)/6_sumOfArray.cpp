#include<iostream>

int getSum(int* arr, int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return arr[0];
    int sum = arr[0] + getSum(arr+1, n-1);
    return sum;
}

int main(){
    int arr[5] = {11, 5, 8, 3, 2};
    int size = 5;
    int ans = getSum(arr, size);
    std::cout<<ans;
    return 0;
}