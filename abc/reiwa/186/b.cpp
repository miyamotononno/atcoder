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
int H, W;
int A[102][102];

int main() {
  INCANT;
  cin >> H >> W;
  int MIN =INF;
  int sum = 0;
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
      sum+=A[i][j];
      MIN = min(A[i][j], MIN);
    }
  }

  cout << sum-MIN*H*W << endl;
  return 0;
}