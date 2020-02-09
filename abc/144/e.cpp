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

  ll r = 1e12; // 練習回数の最長
  ll l = -1ll; // 練習回数の最短
  while (l+1 < r) {
    ll median = (l+r)/2;
    ll sum = 0ll;
    rep(i, N) sum += max(0ll, A[i]- (median/F[i]));
    if (sum <= K) r = median;
    else l = median;
  }
  cout << r << "\n";
  return 0;
}