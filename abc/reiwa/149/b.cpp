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
ll A, B, K;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B >> K;
  ll a=0ll,b=0ll;
  if (A-K>=0) {
    cout << A-K << ' ' << B << "\n";
    return 0;
  }
  ll z = K-A;
  if (B-z>=0) {
    cout << 0 << ' ' << B-z << "\n";
  } else {
    cout << 0 << ' ' << 0 << "\n";
  }

  return 0;
}