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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll n;

bool calc(ll m, int& a) {
  int idx=0;
  while(m%3==0) {
    m/=3;
    idx++;
  }
  a = idx;
  return m==1 && idx>0;
}

int main() {
  INCANT;
  cin >> n;
  int b=1;
  ll y=5;
  while(n>y) {
    int a;
    if (calc(n-y, a)) {
      cout << a <<  ' ' << b << endl;
      return 0;
    }
    y*=5;
    b++;
  }
  cout << -1 << "\n";
  return 0;
}