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
int N, M;
const int MAX_N = 2e5+5;
int par[MAX_N]; //親
int tree_rank[MAX_N]; //木の深さ
int siz[MAX_N]; //木の深さ

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

int main() {
  INCANT;
  cin >> N >> M;
  init(N);
  int a,b;
  rep(i, M) {
    cin >> a >> b;
    a--;b--;
    unite(a,b);
  }
  int mx=0;
  rep(i, N) {
    mx=max(mx, size(i));
  }
  cout << mx << endl;
  return 0;
}