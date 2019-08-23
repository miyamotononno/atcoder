#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
int Memo[101][5][2];
int P[101][10];

int dfs(int idx, vector<int> C, bool flag){
  if (idx==5){
    if (!flag) return -INF;
    int sm = 0;
    rep(i, N){
      sm += P[i][C[i]];
    }
    return sm;
  }
  vector<int> D(N);
  int ans = -INF;
  // 午前営業
  rep(i, N){
    D[i] = C[i];
    if (Memo[i][idx][0]){
      D[i]++;
    }
  }
  ans = max(ans, dfs(idx+1, D, true));

  // 午後営業
  rep(i, N){
    D[i] = C[i];
    if (Memo[i][idx][1]){
      D[i]++;
    }
  }
  ans = max(ans, dfs(idx+1, D, true));

  // 両方営業
  rep(i, N){
    D[i] = C[i];
    if (Memo[i][idx][0]){
      D[i]++;
    }
    if (Memo[i][idx][1]){
      D[i]++;
    }
  }
  ans = max(ans, dfs(idx+1, D, true));

  // 営業しなかった
  ans = max(ans, dfs(idx+1, C, flag));
  return ans;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N){
    rep(j,5){
      rep(k,2){
        cin >> Memo[i][j][k];
      }
    }
  }
  rep(i, N){
    rep(j, 11){
      cin >> P[i][j];
    }
  }
  bool flag = false;
  vector<int> B(N, 0);
  int ans = dfs(0, B, flag);
  cout << ans << "\n";
  return 0;
}