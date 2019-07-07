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
int N, M;
int P[100005], par[100005], tree_rank[100005]; //木の深さ

void init(int n){
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

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  init(N);
  rep(i, N) cin >> P[i];
  int a,b;
  rep(i, M){
    cin >> a >> b;
    unite(a, b);
  }

  int cnt = 0;
  rep(i, N){
    if(P[i]==i+1){
      cnt++;
      continue;
    }
    if(same(P[i], i+1)){
      cnt++;
      continue;
    }
  }

  
  cout << cnt << endl;
  return 0;
}