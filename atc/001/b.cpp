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
const ll MOD = 1000000007LL;
int N, Q;
int par[100000]; //親
int tree_rank[100000]; //木の深さ

// n要素で初期化
void init(int n){
  rep(i, n){
    par[i] = i;
    tree_rank[i] = 0;
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

  if (tree_rank[x] < tree_rank[y]) par[x] = y;
  else{
    par[y] = x;
    if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
  }
}

// xとyが同じ要素に属するかどうか
bool same(int x, int y){
  return find(x) == find(y);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    int p, a, b;
    init(N);
    rep(i, Q){
      cin >> p >> a >> b;
      if(p==0) unite(a,b);
      else{
        if (same(a,b)) cout << "Yes" << endl;
        else cout << "No" << endl;
      }
    }

    return 0;
}