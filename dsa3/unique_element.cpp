#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// only valid when single unique element is present
int findUnique(vector<int> v){
  int ans = 0;
  for(int i = 0; i<v.size(); i++){
    ans = ans ^ v[i];
  }
  return ans;
}

// for first unique element or when muliple unique occurrences are there
int firstUnique(vector<int> v){
  unordered_map<int, int> mp;
  for(int i: v)
    mp[i]++;
  
  // for(auto i: mp){         // for last unique occurrence
  //   if(i.second == 1)
  //     return i.first;
  // }

  for(int i = 0; i<mp.size(); i++){     // for first unique occurrence
    if(mp[i] == 1)
      return i;
  }
  return -1;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter "<<n<<" array elemnets: ";
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  cout<<findUnique(arr)<<endl;
  cout<<"First unique element: "<<firstUnique(arr);
  return 0;
}