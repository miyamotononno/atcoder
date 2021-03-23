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
#include <unordered_set>
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
unordered_map<ll, bool> us;

int main() {
  INCANT;
  cin >> n;
  int cnt = 0;
  for (ll a=2ll; a*a<=n; a++) {
    ll d = a*a;
    while(d<=n) {
      if (!us[d]) {
        cnt++;
        us[d]=true;
      }
      d*=a;
    }
  }
  cout << n-cnt << "\n";
  return 0;
}