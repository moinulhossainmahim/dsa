#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 123;

bool marked[MAX];

void sieve() {
  for (int i = 2; i * i < MAX; i++) {
    if (marked[i])
      continue;
    for (int j = i * i; j <= MAX; j = j + i) {
      marked[j] = 1;
    }
  }
}

int main() {
  int n;
  cin >> n;
  sieve();
  for (int i = 2; i <= n; i++) {
    if (!marked[i])
      cout << i << " ";
  }
  cout << endl;
}
