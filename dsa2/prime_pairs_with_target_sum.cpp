#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// prime pairs with target sum = n
vector<vector<int>> findPrimePairs(int n)
{
  vector<bool> prime(n + 1, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i < n; i++)
  {
    if (prime[i])
    {
      for (int j = 2 * i; j < n; j = j + i)
        prime[j] = false;
    }
  }

  vector<vector<int>> ans;
  for (int i = 2; i <= n / 2; i++)
  {
    vector<int> temp;
    if (prime[i] && prime[n - i])
    {
      temp.push_back(i);
      temp.push_back(n - i);
      ans.push_back(temp);
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main(){
  int n = 5;
  vector<vector<int>> ans = findPrimePairs(n);
  for(int i = 0; i<ans.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans[i].size(); j++)
      cout<<ans[i][j]<<" ";
    cout<<"]";
  }
}