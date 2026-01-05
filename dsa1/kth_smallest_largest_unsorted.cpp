#include <bits/stdc++.h>
using namespace std;

int kthSmallestElement(vector<int> arr, int k) {
  int n = arr.size();
  priority_queue<int> pq;
  for(int i = 0; i < k; i++){
    pq.push(arr[i]);
  }
  for(int i = k ; i < n; i++){
    if(arr[i] < pq.top()){
      pq.pop();
      pq.push(arr[i]);
    }
  }
  int ans = pq.top();
  return ans;
}

int kthLargest(vector<int> arr,int K){
  int size = arr.size();
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < K; i++)
		pq.push(arr[i]);

	for(int i = K; i < arr.size(); i++){
		if(arr[i] > pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}

	int ans = pq.top();
	return ans;
}

int main(){
  vector<int> arr = {2,1,5,6,3,8};
  int k = 3;
  cout<<kthSmallestElement(arr, k)<<endl;
  cout<<kthLargest(arr, k)<<endl;
  return 0;
}