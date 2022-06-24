#include<bits/stdc++.h>

using namespace std;

#define M 100000
bool marked[M];

void sieve(int n) {
  int i,j;
  for(i=2; i*i<n; i++) {
    if(marked[i]==false) {
      for(j=i*i; j<=n; j=j+i) {
        marked[j]=true;
      }
    }
  }
}

bool isPrime(int n) {
  if(n<2)return false;
  if(n==2)return true;
  if(n%2==0)return false;
  return marked[n]==false;
}

int main() {
  sieve(1000);
  int i=2;
  for(; i<=100; i++) {
    if(!marked[i])cout<<i<<" ";
  }
  cout<<endl;
  if(isPrime(10)) {
    cout<<"It's a prime number"<<endl;
  } else {
    cout<<"It's not a prime number"<<endl;
  }
  return 0;
}
