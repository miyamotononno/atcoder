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

map<pair<int, int>, int> ansMap;
int N, K, L;
int a_par[200003]; //親
int b_par[200003]; //木の深さ

// n要素で初期化
void init(int n){
  rep(i, n){
    a_par[i] = i;
    b_par[i] = i;
  }
}

// 木の根を求める
int find(int* c, int x){ 
  if (c[x] == x) return x;
  else return c[x] = find(c, c[x]);
}

// xとyの属する集合を併合
void unite(int* c, int x, int y){
  int root_x = find(c, x);
  int root_y = find(c, y);
  if (root_x == root_y) return;
  c[root_x] = root_y;
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K >> L;
  int p,q,r,s;
  init(N);
  rep(i, K){
    cin >> p >> q;
    unite(a_par, p-1, q-1);
  }

  rep(i, L){
    cin >> r >> s;
    unite(b_par, r-1, s-1);
  }

  pair<int, int> P[N];
  rep(i, N){
    pair<int, int> p(find(a_par, i), find(b_par, i));
    P[i] = p;
    ansMap[p]++;
  }

  rep(i, N){
    if (i==N-1){
      cout << ansMap[P[i]] << endl;
      break;  
    }
    cout << ansMap[P[i]] << ' ';
  } 
  
  return 0;
}