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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const ll INF = 1e18;
ll K;

// 二分探索

bool is_large(ll X) {
  return X > K;
}

ll binary_search(ll l, ll r) {
  while(r-l>1) {
    ll mid = (r+l)/2;
    if (is_large(mid)) l = mid;
    else r = mid;
  }
  return r; // lがokならここをlに変更すること。
}