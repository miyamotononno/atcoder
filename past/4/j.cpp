#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
int n, m;
ll X[3];
string s;
typedef pair<int, ll> P;
vector<P> G[100005];
vector<ll> Towns[3];
ll Teleport[6]; // 0->1,1->0, 0->2, 2->0, 1->2,2->1
ll seen[100005];


void init() {
  cin >> n >> m;
  rep(i, 3) cin >> X[i];
  cin >> s;
  rep(i, n) {
    Towns[s[i]-'A'].push_back(i);
  }
  int a,b; ll c;
  rep(i, m){
    cin >> a >> b >> c;
    a--;b--;
    G[a].push_back(P(b,c));
    G[b].push_back(P(a,c));
  }
  memset(Teleport, -1, sizeof(Teleport));
  memset(seen, -1, sizeof(seen));
}

void bfs() {
  queue<P> que;
  que.push(P(0,0ll));
  while(!que.empty()){
    P p = que.front(); que.pop();
    int town= p.first;
    ll f = p.second;
    if (seen[town]>=0ll && seen[town] < f) continue;
    for (auto n: G[town]) {
      int nTown = n.first;
      if (seen[nTown]>=0ll && seen[nTown] <= f+n.second) continue;
      seen[nTown] = f+n.second;
      que.push(P(nTown,f+n.second)); 
    }
    
    switch(s[town]) {
      ll nf;
      case 'A':
        nf = f+X[0];
        if (Teleport[0]<0 || Teleport[0] > nf) {
          Teleport[0] = nf;
          for (auto n: Towns[1]) {
            if (seen[n]>=0ll && seen[n] <= nf) continue;
            seen[n] = nf;
            que.push(P(n ,nf));
          }
        }
        nf = f+X[1];
        if (Teleport[2]<0 || Teleport[2] > nf) {
          Teleport[2] = nf;
          for (auto n: Towns[2]) {
            if (seen[n]>=0ll && seen[n] <=nf) continue;
            seen[n] = nf;
            que.push(P(n,nf));
          }
        }
        break;
      case 'B':
        nf = f+X[0];
        if (Teleport[1]<0 || Teleport[1] > nf) {
          Teleport[1] = nf;
          for (auto n: Towns[0]) {
            if (seen[n]>=0ll && seen[n] <= nf) continue;
            seen[n] = nf;
            que.push(P(n ,nf));
          }
        }
        nf = f+X[2];
        if (Teleport[4]<0 || Teleport[4] > nf) {
          Teleport[4] = nf;
          for (auto n: Towns[2]) {
            if (seen[n]>=0ll && seen[n] <= nf) continue;
            seen[n] = nf;
            que.push(P(n,nf));
          }
        }
        break;
      case 'C':
        nf = f+X[1];
        if (Teleport[3]<0 || Teleport[3] > nf) {
          Teleport[3] = nf;
          for (auto n: Towns[0]) {
            if (seen[n]>=0ll && seen[n] <= nf) continue;
            seen[n] = nf;
            que.push(P(n,nf));
          }
        }
        nf = f+X[2];
        if (Teleport[5]<0 || Teleport[5] > nf) {
          Teleport[5] = nf;
          for (auto n: Towns[1]) {
            if (seen[n]>=0ll && seen[n] <= nf) continue;
            seen[n] = nf;
            que.push(P(n,nf));
          }
        }
        break;
    }
  }
}

int main() {
  INCANT;
  init();
  bfs();

  cout << seen[n-1] << "\n";
  return 0;
}