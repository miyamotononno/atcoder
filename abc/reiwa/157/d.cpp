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
int N, M, K;
vector<int> Ng[100003];
int par[100003]; //親
int tree_rank[100003]; //木の深さ
int siz[100003]; //木の深さ

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

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> K;
  int a, b;
  init(N);
  rep(i, M) {
    cin >> a >> b;
    a--;b--;
    unite(a,b);
    Ng[a].push_back(b);
    Ng[b].push_back(a);
  }
  rep(i, K) {
    cin >> a >> b;
    a--; b--;
    if (same(a, b)) {
      Ng[a].push_back(b);
      Ng[b].push_back(a);
    }
  }
  rep(i, N) cout << size(i) - Ng[i].size() - 1<< ' ';
  cout << "\n";
  return 0;
}