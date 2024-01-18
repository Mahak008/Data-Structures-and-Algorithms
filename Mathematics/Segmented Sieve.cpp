#include <bits/stdc++.h>
using namespace std;

int N = 1000000;
vector <bool> sieve(N + 1, true);

void createSieve() {
  for(int i = 2; i <= N;i++) {
    sieve [i] = true;
  }

  for(int i = 2; i*i <= N;i++) {
    if (sieve [i] == true) {
      for(int j = i*i; j <= N; j+=i) {
        sieve [j] = false;
      }
    }
  }
}

vector<int> generatePrimes (int N) {
  vector <int> ds;
  for(int i = 2; i <= N; i++) {
    if(sieve[i] == true) {
      ds.push_back(i);
    }
  }
  return ds;
}

int main() {
  createSieve();
  // step 1: generate all primes till sqrt(r)
}
