#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll n;

int calcDigit(ll x) {
  int cnt = 0;
  while(x > 0) {
    x/=10ll;
    cnt++;
  }
  return cnt;
}

int findCount(ll n) {
  ll cur = 1;
  int sz = 1;
  while(cur*pow(10ll, sz)+cur<=n) {
    cur++;
    sz = calcDigit(cur);
  }
  return cur-1;
}

int main() {
  INCANT;
  cin >> n;
  cout << findCount(n) << "\n";
  return 0;
}