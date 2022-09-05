#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 32000

vector<int> primes;

void sieve() {
  bool isPrime[MAX];
  for (int i = 2; i * i < MAX; i++) {
    if (isPrime[i])
      continue;
    for (int j = i * i; j <= MAX; j += i) {
      isPrime[j] = true;
    }
  }
  primes.push_back(2);
  for (int i = 3; i < MAX; i += 2) {
    if (!isPrime[i])
      primes.push_back(i);
  }
}

void segSieve(ll l, ll r) {
  bool isPrime[r - l + 1];
  for (int i = 0; i < r - l + 1; i++)
    isPrime[i] = true;
  if (l == 1)
    isPrime[0] = false;
  for (int i = 0; primes[i] * primes[i] <= r; i++) {
    int currPrime = primes[i];
    ll base = (l / currPrime) * currPrime;
    if (base < l)
      base += currPrime;

    for (int j = base; j <= r; j += currPrime) {
      isPrime[j - l] = false;
    }

    if (base == currPrime)
      isPrime[base - l] = true;
  }

  for (int i = 0; i < r - l + 1; i++) {
    if (isPrime[i])
      cout << (i + l) << endl;
  }
}

int main() {
  sieve();
  int tt;
  cin >> tt;
  while (tt--) {
    ll l, r;
    cin >> l >> r;
    segSieve(l, r);
  }
}
