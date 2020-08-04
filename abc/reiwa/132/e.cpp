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
vector<int> G[300005];
int d[300005];

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int u, v;
  rep(i, M){
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v+N);
    G[u+N].push_back(v+2*N);
    G[u+2*N].push_back(v);
  }
  int s,t;
  cin >> s >> t;
  s--, t--;

  queue<int> q;
  q.push(s);
  rep(i, 3*N) d[i] = -1;
  d[s] = 0;
  while(!q.empty()){
    int k = q.front(); q.pop();
    rep(i, G[k].size()){
      int n = G[k][i];
      if(d[n] < 0){
        q.push(n);
        d[n] = d[k]+1; 
      }
    }
  }

  if (d[t]==-1) cout << -1 << endl;
  else cout << d[t] / 3 << endl;
}