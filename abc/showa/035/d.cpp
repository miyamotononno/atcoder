#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll INF = 1e16;
int N, M;
ll T, A[100005];
typedef pair<ll, int> P;
vector<P> G1[100005], G2[100005];
ll D1[100005], D2[100005];

void dijkstra(vector<P> G[100005], ll D[100005]) {
  fill(D, D+N, INF);
  D[0] = 0ll;
  queue<P> que;
  que.push(P(0ll, 0));
  while(!que.empty()) {
    P p = que.front(); que.pop();
    if (p.first > D[p.second]) continue;
    D[p.second] =p.first;
    for (auto n: G[p.second]) {
      if (D[n.second] > n.first+p.first) {
        D[n.second] = n.first+p.first;
        que.push(P(n.first+p.first, n.second));
      }
    }
  }
}

int main() {
  INCANT;
  cin >> N >> M >> T;
  rep(i, N) cin >> A[i];
  int a,b;ll c;
  rep(i, M) {
    cin >> a >> b >> c;
    a--; b--;
    G1[a].push_back(P(c,b));
    G2[b].push_back(P(c,a));
  }
  dijkstra(G1, D1);
  dijkstra(G2, D2);
  ll ANS=0ll;
  rep(i, N) {
    if (D1[i]==INF || D2[i]==INF) continue;
    ANS=max(ANS, (T-D1[i]-D2[i])*A[i]);
  }
  cout << ANS << endl;
  return 0;
}