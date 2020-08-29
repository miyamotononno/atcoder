#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N;
int A[1000006];
int GCD[1000006];
unordered_map<int, bool> is_prime;

bool prime_factor(int n) {
  for(int i = 2; i * i <= n; i++) {
    if (n%i==0) {
      if (is_prime[i]) return true;
      else is_prime[i] = true;
    }
    while(n % i == 0) n /= i;
  }
  if(n != 1) {
    if (is_prime[n]) return true;
    else is_prime[n] = true;
  }
  return false;
}

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  GCD[0] = A[0];
  rep(i, N-1) GCD[i+1] = gcd(GCD[i], A[i+1]);
  if (GCD[N-1]>=2) {
    cout << "not coprime" << endl;
    return 0;
  }
  rep(i, N) {
    if (prime_factor(A[i])) {
      cout << "setwise coprime" << endl;
      return 0;
    }
  }
  
  cout << "pairwise coprime" << endl;
  return 0;
}