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
const int MAX_N = 2e5+10;
int par[MAX_N]; //親
int tree_rank[MAX_N]; //木の深さ
struct Query{int com, a,b;};
vector<Query> Q;


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
int unite(int x, int y){
  if (x == y) return -1;

  if (tree_rank[x] < tree_rank[y]) {
    par[x] = y;
    return y;
  }
  else{
    par[y] = x;
    if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
    return x;
  }
}

int main(){
  INCANT;
  int n, q;
  cin >> n >> q;
  int c;
  vector<map<int, int> > Conflu(n);
  rep(i, n) {
    cin >> c;
    c--;
    Conflu[i][c]=1;
  }
  int com,a,b;
  rep(i, q) {
    cin >> com >> a >> b;
    Query query = {com, a-1, b-1};
    Q.push_back(query);
  }
  init(n);
  for (auto query: Q) {
    int x = find(query.a);
    if (query.com==1) {
      int y = find(query.b);
      int r = unite(x,y);
      if (r>=0) {
        
        if (r!=x) swap(x,y);
        for (auto p: Conflu[y]) {
          Conflu[x][p.first] += p.second;
        }
      }
    } else {
      cout << Conflu[x][query.b] << endl;
    }
  }
}