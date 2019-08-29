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
typedef pair<int, ll> P;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N, Q, K;
vector<P> Tree[100003];
vector<ll> Mp(100003);

void dfs(int idx, ll cost){
  if (idx==K || Mp[idx]==0){
    Mp[idx] = cost;
    rep(i, Tree[idx].size()){
      int nxt = Tree[idx][i].first;
      if (nxt==K) continue;
      ll ct = Tree[idx][i].second;
      dfs(nxt, cost+ct);
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a,b;
  ll c;
  rep(i,N-1){
    cin >> a >> b >> c;
    a--;b--;
    P p1 = make_pair(b, c);
    P p2 = make_pair(a, c);
    Tree[a].push_back(p1);
    Tree[b].push_back(p2);
  }
  cin >> Q >> K;
  K--;
  dfs(K, 0ll);
  rep(i, Q){
    cin >> a >> b;
    a--; b--;
    cout << Mp[a] + Mp[b] << "\n";
  }

  return 0;
}