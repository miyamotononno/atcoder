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
int K;

int main() {
  INCANT;
  cin >> K;
  ll ret= 0;
  rep(i, K) {
    rep (j, K) {
      rep (k, K) {
        ret+=gcd(i+1, j+1, k+1);
      }
    }
  }
  cout << 6*ret << "\n";
  return 0;
}
