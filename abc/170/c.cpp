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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int x,n;
bool p[102];

int main() {
  INCANT;
  cin >> x >> n;
  int a;
  rep(i, n) {
    cin >> a;
    p[a] = true;
  }
  if (!p[x]) {
    cout << x << endl;
    return 0;
  }
  int lower=0;
  for (int i = x; i>=1; i--) {
    if (!p[i]) {
      lower = i;
      break;
    }
  }
  int higher=101;
  for (int i = x; i<=100; i++) {
    if (!p[i]) {
      higher = i;
      break;
    }
  }
  if (higher-x<x-lower) {
    cout << higher << endl;
  } else cout << lower << endl;
  return 0;
}