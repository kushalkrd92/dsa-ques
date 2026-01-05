// shipping cost
#include <bits/stdc++.h>
using namespace std;

int main(){
  double w = 10, d = 1360.5;
  double base = 5.00;
  double costperkg = 2.00;
  double costperkm = 0.05;
  double ans = 0;
  ans = base + w*costperkg + d*costperkm;
  printf("$%.2f", ans);
  return 0;
}