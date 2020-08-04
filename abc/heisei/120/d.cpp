#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <map>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 1e9+7;
int N, M;
int par[100005], tree_rank[100005], siz[100005], C[100005][2];
ll anslist[100005];

// n要素で初期化
void init(int n){
  rep(i, n){
    par[i] = i;
    tree_rank[i] = 0;
    siz[i] = 1;
  }
}

// 木の根を求める
int find(int x){
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

// xとyの属する集合を併合
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (tree_rank[x] < tree_rank[y]) {
    par[x] = y;
    int tmp = siz[x];
    siz[x] += siz[y];
    siz[y] = siz[x];
  }
  else{
    par[y] = x;
    int tmp = siz[x];
    siz[x] += siz[y];
    siz[y] = siz[x];
    if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
  }
}

// xとyが同じ要素に属するかどうか
bool same(int x, int y){
  return find(x) == find(y);
}

int size(int x) { // 素集合のサイズ
  return siz[find(x)];
}

ll connect_count_in_tree(int a) {
  ll sz = (ll) size(a);
  return sz*(sz-1)/2;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int a,b;
  rep(i, M) {
    cin >> a >> b;
    a--;b--;
    C[i][0] = a;
    C[i][1] = b;
  }
  init(N);
  ll ans = (ll) N*(N-1)/2;
  anslist[M-1] = ans;
  for (int i=M-1; i>=1; i--) {
    a = C[i][0]; b = C[i][1];
    ll pre_a_size = connect_count_in_tree(a);
    ll pre_b_size = connect_count_in_tree(b);
    if (!same(a, b)) {
      unite(a, b);
      ans += pre_a_size + pre_b_size;
      ll tmp = connect_count_in_tree(a);
      ans -= tmp;
    }
    anslist[i-1] = ans;
  }

  rep(i, M) cout << anslist[i] << "\n";
  return 0;
}