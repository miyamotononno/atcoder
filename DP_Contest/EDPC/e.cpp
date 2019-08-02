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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
struct edge {int cost, value;}; 
int N, W;
edge L[103];
int DP[103][100003]; // 日数, 取り得るvalue。 resは最小の重さ

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> W;
  int w, v;
  rep(i, N) {
    cin >> w >> v;
    edge e = {w, v};
    L[i] = e;
  }
  fill(DP[0], DP[0]+100003, 1000000007);
  DP[0][0] = 0;

  // i-1番目の品物から価値の総和がjとなるように選ぶ
  // i-1番目の品物から価値の総和がjーv[i]となるように選び、i番目の品物を加える。
  rep(i, N) {
    int v = L[i].value;
    int w = L[i].cost;
    rep(j, 100003) {
      if (j < v) {
        DP[i+1][j] = DP[i][j];
      } else {
        DP[i+1][j] = min(DP[i][j], DP[i][j-v] + w);
      }
    }
  }

  int res = 0;
  rep(i, 100003){
    if (DP[N][i] <= W) res = i;
  }

  cout << res << endl;;
  return 0;
}