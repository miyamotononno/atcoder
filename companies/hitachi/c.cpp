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
int N;
vector<int> Tree[200002];
queue<int> Q[3]; 
int ans[200002];
int guuki[200002];

/*
「すべての頂点の組 (i,j)について、頂点 iと頂点jの距離が3であるならば、
piと pjの和または積が3の倍数である。」の対偶は、
「[pi≡1かつpj≡1]または[pi≡2かつpj≡2](mod3)ならば、iとjの距離は3でない」
である。
頂点1からの距離が偶奇でわけたときに、3の距離となるときは頂点が偶と奇。
*/
void dfs(int idx, int mod2) { // mod2は0or1
  guuki[idx] = mod2;
  mod2=mod2?0:1;
  rep(i, Tree[idx].size()) {
    int next = Tree[idx][i];
    if (guuki[next]<0) dfs(next, mod2);
  }
}

bool assign_and_pop(int idx, int mod3) {
  if (Q[mod3].empty()) return false;
  ans[idx] = Q[mod3].front();
  Q[mod3].pop();
  return true;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a,b;
  rep(i, N-1) {
    cin >> a >> b;
    a--;b--;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
  }
  fill(guuki, guuki+N, -1);
  dfs(0, 0);
  int even = 0;
  int odd = 0;
  rep(i, N) {
    Q[(i+1)%3].push(i+1);
    assert(guuki[i]>=0);
    if (guuki[i]) odd++;
    else even++;
  }
  bool odd_flag = odd<=N/3; // 距離が奇数の頂点がN/3以下
  bool even_flag = even<=N/3; // 距離が偶数の頂点がN/3以下
  if (odd_flag) {
    rep(i, N) {
      if (guuki[i]) assign_and_pop(i, 0);
      else {
        bool ok = assign_and_pop(i, 1);
        if (ok) continue;
        bool ok2 = assign_and_pop(i, 2);
        if (ok2) continue;
        assign_and_pop(i, 0);
      }
    }
  }
  else if (even_flag) {
    rep(i, N) {
      if (!guuki[i]) assign_and_pop(i, 0);
      else {
        bool ok = assign_and_pop(i, 1);
        if (ok) continue;
        bool ok2 = assign_and_pop(i, 2);
        if (ok2) continue;
        assign_and_pop(i, 0);
      }
    }
  }
  else {
    rep(i, N) {
      if (guuki[i]) {
        bool ok = assign_and_pop(i, 1);
        if (!ok) assign_and_pop(i, 0);
      } else {
        bool ok = assign_and_pop(i, 2);
        if (!ok) assign_and_pop(i, 0);
      }
    }
  }
  rep(i, N) {
    assert(ans[i]<=N);
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
