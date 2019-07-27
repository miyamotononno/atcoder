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
int N;
int c[100005];
vector<pair<int, int> > g[100005];

void dfs(int u, int p, int o){
  c[u] = o;
  for(pair<int, int> v: g[u]){
    if (v.first != p) dfs(v.first, u, (o+v.second)%2);
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N-1){
    int u,v,w;
    cin >> u >> v >> w;
    w%=2;
    pair<int, int> a = make_pair(v,w);
    g[u].push_back(a);
    <int, int> b = make_pair(u,w);
    g[v].push_back(b);
  }

  dfs(1,0,0); // 1始まりなので。
  for(int i=1; i <=N; i++) cout << c[i] << endl;

  return 0;
}