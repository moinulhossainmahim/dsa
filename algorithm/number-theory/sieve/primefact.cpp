#include<bits/stdc++.h>
#define MAX 32000
using namespace std;


int item[128];
int listSize;

vector<int>prime;

void sieve(int n) {
  bool isPrime[MAX];
  for(int i=0; i<MAX; i++)isPrime[i]=true;
  for(int i=3; i*i<=MAX; i++) {
    if(isPrime[i]) {
      for(int j=i*i; j<=MAX; j=j+i) {
        isPrime[j]=false;
      }
    }
  }
  prime.push_back(2);
  for(int i=3; i<=n; i+=2) {
    if(isPrime[i])prime.push_back(i);
  }
}

void primeFactorize(int n) {
  sieve(sqrt(n)+1);
  listSize=0;
  for(int i=0; prime[i]*prime[i]<=n; i++) {
    if(n%prime[i]==0) {
      while(n%prime[i]==0) {
        n/=prime[i];
        item[listSize]=prime[i];
        listSize++;
      }
    }
  }
  if(n>1) {
    item[listSize++]=n;
  }
}

int main() {
  primeFactorize(114);
  for(int i=0; i<listSize; i++) {
    cout<<item[i]<<endl;
  }
  return 0;
}
