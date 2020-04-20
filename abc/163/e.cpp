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
int N;
typedef pair<ll, int> P;
P A[2001];
ll DP[2001][2001]; // left人とright人の幸福度

int main() {
  INCANT;
  cin >> N;
  ll a;
  rep(i, N) {
    cin >> a;
    A[i] = P(a, i);
  }
  sort(A,A+N, greater<P>());
  
  rep(i, N) {
    P p = A[i];
    for (int j=0; j<=i; j++) { // i人並んでいる
      int left = j;
      int right = i-j;
      int right_idx = N-1-right;
      DP[left+1][right] = max(DP[left+1][right], DP[left][right]+p.first*abs(p.second-left)); // 左側に並ぶ
      DP[left][right+1] = max(DP[left][right+1], DP[left][right]+p.first*abs(right_idx-p.second)); // 右側に並ぶ
    }
  }
  ll MAX=0ll;
  rep(i, N+1) MAX = max(MAX, DP[i][N-i]);
  cout << MAX << endl;
  return 0;
}