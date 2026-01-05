#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> closestPrimes(int left, int right){
  // Sieve of Eratosthenes
  vector<bool> sieve(right + 1, true);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i <= right; i++)
  {
    if (sieve[i])
    {
      for (int j = i * 2; j <= right; j += i)
        sieve[j] = false;
    }
  }

  // Collecting Primes
  vector<int> primes;
  for (int i = left; i <= right; i++)
  {
    if (sieve[i])
      primes.push_back(i);
  }

  if (primes.size() < 2)
    return {-1, -1};

  // Finding the Closest Pair
  int minDiff = INT_MAX;
  vector<int> ans(2, -1);
  for (int i = 1; i < primes.size(); i++)
  {
    int diff = primes[i] - primes[i - 1];
    if (diff < minDiff)
    {
      ans = {primes[i - 1], primes[i]};
      minDiff = diff;
    }
  }
  return ans;
}

int main(){
  int s, e;
  cout<<"Enter range: ";
  cin>>s>>e;
  vector<int> ans = closestPrimes(s, e);
  for(int i: ans)
    cout<<i<<" ";
  return 0;
}