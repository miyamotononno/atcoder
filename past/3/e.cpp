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
int N, M, Q, color[201];
vector<int> G[201];
int Query[201][3];

int main() {
  INCANT;
  cin >> N >> M >> Q;
  int u,v;
  rep(i, M)  {
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  rep(i, N) cin  >> color[i];
  rep(i, Q) {
    cin >> Query[i][0];
    if (Query[i][0]==1) {
      cin >> Query[i][1];
      Query[i][1]--;
    } else {
      cin >> Query[i][1];
      Query[i][1]--;
      cin >> Query[i][2];
    }
  }
  rep(i, Q) {
    int idx = Query[i][1];
    if (Query[i][0]==1) {
      cout << color[idx] << endl;
      for (auto p: G[idx]) color[p] = color[idx];
    } else {
      cout << color[idx] << endl;
      color[idx] = Query[i][2];
    }
  }

  return 0;
}