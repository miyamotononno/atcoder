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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n, m;
ll A[200005], B[200005];
vector<ll> G[200005];
const int MAX_N = 2e5+10;
int par[MAX_N]; //親
int tree_rank[MAX_N]; //木の深さ
int siz[MAX_N]; //木の深さ


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
  }
  else{
    par[y] = x;
    if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
  }
}

// xとyが同じ要素に属するかどうか
bool same(int x, int y){
  return find(x) == find(y);
}

int number_of_connected_compoents(int n) { // 連結成分数(何個のグラフに分かれているか)
  set<int> S;
  rep(i, n) S.insert(find(i));
  return S.size();
}

int main() {
  INCANT;
  cin >> n >> m;
  init(n);
  rep(i, n) {
    cin >> A[i];
  }
  rep(i, n) {
    cin >> B[i];
  }
  ll a,b;
  rep(i, m) {
    cin >> a >> b;
    a--;b--;
    unite(a, b);
  }
  unordered_map<int, vector<int> > U;
  rep(i, n) {
    int godNode = find(i);
    U[godNode].push_back(i);
  }
  ll suma, sumb;
  for (auto u: U) {
    suma=sumb=0ll;
    for(auto c: u.second) {
      suma+=A[c];
      sumb+=B[c];
    }
    if (suma!=sumb) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}