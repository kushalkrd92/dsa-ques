#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid){
  int cowCount = 1;
  int lastPos = stalls[0];
  for(int i = 0; i<stalls.size(); i++){
    if(stalls[i] - lastPos >= mid){             // distance bw them >= mid
      cowCount++;
      if(cowCount == k)
        return true;
      lastPos = stalls[i];
    }
  }
  return false;
}

// aggressive cows
// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Print the maximum possible minimum distance.
int aggressiveCows(vector<int> &stalls, int k){
  sort(stalls.begin(), stalls.end());
  int s = 0;
  int maxi = -1;
  for(int i = 0; i<stalls.size(); i++){
      maxi = max(maxi, stalls[i]);
  }
  int e = maxi;
  int ans = -1;
  while(s <= e){
    int mid = s + (e-s)/2;
    if(isPossible(stalls, k, mid)){
        ans = mid;
        s = mid + 1;
    }
    else
        e = mid - 1;
  }
  return ans;
}

// Magnetic Force Between Two Balls
// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
// Given the integer array position and the integer m. Return the required force.
int maxDistance(vector<int>& position, int m) {
  sort(position.begin(), position.end());
  int n = position.size();
  int s = 0;
  int maxi = -1;
  for(int i: position)
    maxi = max(maxi, i);
  int e = maxi;
  int ans = -1;
  
  while(s <= e){
    int mid = s + (e-s)/2;
    if(isPossible(position, m, mid)){
      ans = mid;
      s = mid + 1;
    }
    else
      e = mid - 1;
  }
  return ans;
}

int main(){
  vector<int> arr = {5,4,3,2,1,1000000000};
  int k = 2;
  cout<<endl;
  cout<<aggressiveCows(arr, k)<<endl;
  cout<<maxDistance(arr, k)<<endl;
  return 0;
}