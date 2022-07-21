#include<bits/stdc++.h>

using namespace std;

int dp[INT16_MAX];

int fibo(int n) {
  if(n==0) return 0;
  if(n==1) return 1;
  if(dp[n] != -1) return dp[n];
  return dp[n] = fibo(n-1) + fibo(n-2);
}

int main() {
  memset(dp, -1, sizeof(dp));
  cout << fibo(5) << endl;
  return 0;
}
