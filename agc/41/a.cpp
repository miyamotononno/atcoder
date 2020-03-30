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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll N, A, B;

ll calc(ll sml, ll lrg) {
  if (sml - 1 < N-lrg) {
    // 卓1に集合する
    return sml - 1 + 1 + (lrg-sml-1)/2;
  }
  return N-lrg +1 + (lrg-sml-1)/2;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> A >> B;
  if ((A-B)%2==0) {
    cout << abs(A-B) /2 << "\n";
    return 0;
  }

  cout << calc(min(A,B), max(A,B)) << "\n";
  return 0;
}