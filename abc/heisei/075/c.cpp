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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N, M;
int A[51], B[51];
vector<int> Mp[51];
int par[51]; //親
int tree_rank[51]; //木の深さ

void init_union_find(int n){
  rep(i, n){
    par[i] = i;
    tree_rank[i] = 0;
  }
}

int find(int x){
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

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

bool same(int x, int y){
  return find(x) == find(y);
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int a, b;
  rep(i, M){
    cin >> a >> b;
    a--; b--;
    A[i] =a;
    B[i] =b;
  }
  int ans=0;
  rep(i, M){
    init_union_find(N);
    rep(j, M){
      if (j==i) continue;
      int a = A[j];
      int b = B[j];
      if(!same(a, b)){
        unite(a,b);
      }
    }
    if (!same(A[i], B[i])) ans++;
  }
  cout << ans << "\n";
  return 0;
}