#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define Max 32000
vector<int> primes;

void sieve() {
  bool isPrime[Max];
  int i,j;
  for(i=0; i<Max; i++)isPrime[i]=true;
  for(i=3; i*i<=Max; i++) {
    if(isPrime[i]) {
      for(j=i*i; j<=Max; j+=i) {
        isPrime[j]=false;
      }
    }
  }
  primes.push_back(2);
  for(i=3; i<Max; i+=2){
    if(isPrime[i]) primes.push_back(i);
  }
  for(i=0; i<5; i++) {
    cout<<primes[i]<<" ";
  }
  cout<<endl;
}

int main() {
  sieve();
  return 0;
}
