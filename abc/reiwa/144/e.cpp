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
const int INF = 2e9;
int N;
ll K; 
vector<int> A, F;
// 二分探索

bool is_large(ll X) {
  ll sum = 0ll;
  rep(i, N) sum += max(0ll, A[i]- (X/F[i]));
  return sum > K;
}

ll binary_search(ll l, ll r) {
  while(r-l>1) {
    ll mid = (r+l)/2;
    if (is_large(mid)) l = mid;
    else r = mid;
  }
  return r;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  ll a;
  rep(i, N) {
    cin >> a;
    A.push_back(a);  
  }
  rep(i, N) {
    cin >> a;
    F.push_back(a);  
  }
  sort(ALL(A));
  sort(ALL(F),greater<ll>());

  ll ok = 1e13;
  ll ng = -1;
  cout << binary_search(ng, ok) << "\n";
  return 0;
}