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
using namespace std;
const int MAX_N = 1e5+10;
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

int number_of_connected_compoents(int n) { // 連結成分数(何個のグラフに分かれているか)
  set<int> S;
  rep(i, n) S.insert(find(i));
  return S.size();
}

