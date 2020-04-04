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
int H, N, A[1001], B[1001];
int DP[20003]; // 0-idx番目の魔法を使える, 減らせる体力0-H. 最小の魔力
typedef pair<int, int> P;
P C[1001];
int max_tai;

void calc(int idx) {
  P p = C[idx];
  int b = p.first, a = p.second; //bは魔力、aは体力
  rep(i, H+a) {
    DP[i] = min(DP[max(i-a, 0)]+b, DP[i]);
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> N;
  rep(i, N) {
    cin >> A[i] >> B[i];
    C[i] = P(B[i], A[i]);
    max_tai = max(max_tai, A[i]);
  }
  sort(C, C+N);
  rep(j, H+max_tai) DP[j+1] = INF;
  rep(i, N) calc(i);
  int ans = INF;
  rep(i, max_tai) {
    ans = min(ans, DP[H+i]);
  }
  cout << ans << "\n";
  return 0;
}