#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>        // sort
using namespace std;

// find duplicate
// for single duplicate element and when elements lie from 1 to N-1
int findDuplicate(vector<int> arr){
  int ans = 0;
  for(int i = 0; i<arr.size(); i++)
    ans = ans ^ arr[i];
  for(int i = 1; i<arr.size(); i++)
    ans = ans ^ i;
  return ans;
}

// for a single element repeated twice, when elements lie from 1 to N and without using auxiliary space
// Floyd's Tortoise and Hare algorithm, also known as Floyd's Cycle Detection algorithm
int findDuplicate1(vector<int> arr){
  int slow = arr[0];
  int fast = arr[0];
  while(true){
    slow = arr[slow];
    fast = arr[arr[fast]];
    if(slow == fast)
      break;
  }
  int slow2 = arr[0];
  while(slow != slow2){          // note below
    slow = arr[slow];
    slow2 = arr[slow2];
  }
  return slow;
}

// for single element repeated multiple times (more than twice) and when elements lie from 1 to N-1
int findDuplicate2(vector<int> arr){
  unordered_set<int> s;
  for(int i: arr){
    if(s.find(i) != s.end())
      return i;
    s.insert(i);
  }
  return -1;
}

// for single element repeated multiple times (more than twice) and when elements lie from 1 to N-1 without using set
int findDuplicate3(vector<int> arr){
  sort(arr.begin(), arr.end());
  for(int i = 0; i<arr.size(); i++){
    if(arr[i] == arr[i+1] && i+1 < arr.size())
      return arr[i];
  }
  return -1;
}

// for multiple elements repeated multiple times (more than twice), returning the unique repeated elements in sorted order
vector<int> duplicatedElements(vector<int> arr){
  unordered_set<int> s, ans;
  vector<int> result;
  for(int i: arr){
    if(s.find(i) != s.end())
      ans.insert(i);
    else
      s.insert(i);
  }
  for(int i: ans)
    result.push_back(i);
  sort(result.begin(), result.end());
  return result;
}

// for multiple elements repeated twice, returning the unique repeated elements in sorted order, and when elements lie from 1 to N and without using auxiliary space
vector<int> duplicatedElements2(vector<int> arr){
  vector<int> ans;
  for(int i = 0; i<arr.size(); i++){
    int index = abs(arr[i]) - 1;
    arr[index] = -arr[index];
    if(arr[index] > 0)         // if the element is +ve that means we have editied this element twice
      ans.push_back(index+1);
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main(){
  int n;
  cout<<"Enter size: ";
  cin>>n;
  vector<int> v(n);
  cout<<"Enter "<<n<<" array elements: ";
  for(int i = 0; i<n; i++)
    cin>>v[i];
  cout<<findDuplicate(v)<<endl;
  cout<<findDuplicate1(v)<<endl;
  cout<<findDuplicate2(v)<<endl;
  cout<<findDuplicate3(v)<<endl;

  vector<int> ans = duplicatedElements(v);
  for(int i = 0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
  cout<<endl;

  ans = duplicatedElements2(v);
  for(int i = 0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
  return 0;
}


// Floyd's Tortoise and Hare algorithm, also known as Floyd's Cycle Detection algorithm -

// The second loop with slow and slow2 is necessary to find the starting point of the cycle,
// which corresponds to the duplicate element in the array.

// In the first loop (cycle detection phase) using the Floyd's Tortoise and Hare algorithm,
// we detect that there is a cycle in the array by finding a position where the slow and fast pointers meet.
// However, this position is not necessarily the starting point of the cycle or the duplicate element. 
// It's just a position within the cycle.

// The second loop (cycle start detection phase) helps us find the actual starting point of the cycle,
// which is the duplicate element we are looking for. The starting point of the cycle is the position 
// where the slow and slow2 pointers meet. This second loop is crucial to pinpoint the exact duplicate 
// element in the array.

// Without this second loop, we would have detected the presence of a cycle but would not have determined
// the duplicate element. The second loop is essential for identifying the duplicate element within the cycle.