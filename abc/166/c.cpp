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
int N, M, H[100005];
vector<int> G[100005];
int Ans[100005];

void dfs(int idx, int prev) { // prevがtrueはprevの方が高い
  if (Ans[idx]>=0) return;
  vector<int> vec = G[idx];
  bool flag = true;
  if (!prev) {
    rep(i, vec.size()) {
      int n = vec[i];
      if (H[n]>=H[idx]) {
        flag = false;
        break;
      }
    }
  } else flag = false; // 可能性もあるというだけ
  Ans[idx]=flag?1:0;
  rep(i, vec.size()) {
    int n = vec[i];
    dfs(n, flag);
  }
}

int main() {
  INCANT;
  cin >> N >> M;
  rep(i, N) cin >> H[i];
  int a,b;
  rep(i, M) {
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i, N) Ans[i]=-1;
  rep(i, N) dfs(i,false);
  int ans=0;
  rep(i, N) ans+=Ans[i];
  cout << ans << "\n";
  return 0;
}