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
typedef long long ll;
using namespace std;
const ll MOD = 998244353;
int N, K;
typedef pair<int, int> P;
vector<P> A;
ll DP[200005], sumDP[200005]; // 0...n-1までのDPの和をSUMDP[n]


int main() {
  INCANT;
  cin >> N >> K;
  int l,r;
  rep(i, K) {
    cin >> l >> r;
    A.push_back(P(l, r));
  }
  DP[0] = sumDP[1] = 1ll;
  for (int n = 1; n < N; ++n) {
    for (auto p: A) {
      int left = max(0, n-p.second);
      int right = max(0, n-p.first+1);
      DP[n] += sumDP[right] - sumDP[left];
      DP[n]%=MOD;
    }
    sumDP[n+1] = sumDP[n] + DP[n];
    sumDP[n+1] %= MOD;
  }
  if (DP[N-1] < 0) DP[N-1]+=MOD;
  cout << DP[N-1] << "\n";
  return 0;
}