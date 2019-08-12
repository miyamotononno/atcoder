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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;

// 素因数分解
// prime_factor(n):=自然数nを素因数分解した結果を返す。計算量はO(√n)

map< int, int > prime_factor(int n) {
  map< int, int > ret;
  for(int i = 2; i * i <= n; i++) {
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
  int N;
  cin >> N;
  cout << N << ":";
  for(auto p : prime_factor(N)) {
    while(p.second--) cout << " " << p.first;
  }
  cout << endl;
}