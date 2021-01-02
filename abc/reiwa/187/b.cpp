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
int n;
int X[1003], Y[1003];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) {
    cin >> X[i];
    cin >> Y[i];
  }
  int ret = 0;
  rep(i, n-1) {
    int ax=X[i];
    int ay=Y[i];
    for (int j=i+1; j<n; j++) {
      int bx=X[j];
      int by=Y[j];
      if (ax==bx) continue;
      if (by <= ay+abs(bx-ax) && by >= ay-abs(bx-ax)) ret++;
    } 
  }
  cout << ret << "\n";
  return 0;
}