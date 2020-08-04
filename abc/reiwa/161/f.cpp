#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;

map< ll, int > prime_factor(ll n) {
  map< ll, int > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

// 検証例

int main() {
  ll N;
  cin >> N;
  int ret = 1; // Nを含む
  for(ll i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      ll tmp = N;
      while(tmp%i==0) tmp/=i;
      if (tmp%i==1) ret++;
    }
  }
  int ret2 = 1;
  for(auto p : prime_factor(N-1)) {
    ret2*=(p.second+1);
  }
  ret2--; // 1を除く
  cout << ret+ret2 << endl;
}