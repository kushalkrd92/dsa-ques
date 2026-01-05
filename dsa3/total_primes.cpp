#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes:
// The outer loop iterates over each number i from 2 to 𝑛−1.
// For each number i:
// If prime[i] is true, it means i is a prime number.
// Increment the prime count cnt by 1.
// Mark all multiples of i starting from i*2 as false. The inner loop achieves this by setting prime[j] to false for all multiples j of i.
// This marking ensures that all non-prime numbers are identified and excluded from the count.

// Given an integer n, return the number of prime numbers that are strictly less than n.
int totalPrimes(int n){
  vector<bool> prime(n+1, true);
  prime[0] = prime[1] = false;
  int count = 0;

  for (int i = 2; i < n; i++) {
    if (prime[i]) {
      count++;
      for (int j = 2 * i; j < n; j = j + i)
        prime[j] = false;
    }
  }
  return count;
}

// You are given a positive integer n. Your task is to print all prime numbers less than or equal to n.
vector<int> printPrimes(int n){
  vector<bool> prime(n+1, true);
  vector<int> primes;
  prime[0] = prime[1] = false;

  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j <= n; j = j + i)
        prime[j] = false;
    }
  }
  return primes;
}

// You must return the unique prime factors of 'N' in increasing order. For Example: For ‘N’ = 10. Unique prime factors are 2 and 5.
vector<int> printPrimes2(int n){
  vector<bool> prime(n+1, true);
  vector<int> primes;
  prime[0] = prime[1] = false;

  for (int i = 2; i <= n; i++) {
    if (prime[i] && n%i == 0) {
      primes.push_back(i);
      for (int j = 2 * i; j <= n; j = j + i)
        prime[j] = false;
    }
  }
  return primes;
}

// return the number of prime numbers that lie between s and e, both inclusive
int totalPrimes2(int s, int e){
  vector<bool> sieve(e+1, true);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i <= e; i++) {
    if (sieve[i]) {
      for (int j = 2 * i; j <= e; j += i)
        sieve[j] = false;
    }
  }
  
  int count = 0;
  for(int i = s; i <= e; i++){
    if(sieve[i] == true)
      count++;
  }
  return count;
}

int main(){
  int n, s, e;
  cout<<"Enter n: ";
  cin>>n;
  cout<<"Enter start and end: ";
  cin>>s>>e;
  cout<<totalPrimes(n)<<endl;
  vector<int> ans = printPrimes(n);
  for(int num: ans)
    cout<<num<<" ";
  cout<<endl;

  ans = printPrimes2(n);
  for(int num: ans)
    cout<<num<<" ";
  cout<<endl;

  cout<<totalPrimes2(s, e);
  return 0;
}