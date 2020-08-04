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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, Q, K;
typedef pair<int, ll> P;
vector<P> Tree[100005];
ll dp[100005], Ans[100005][2];

void bfs() {
  queue<P> que;
  que.push(P(K, 0));
  while(!que.empty()) {
    P q = que.front();que.pop();
    dp[q.first] = q.second;
    for (auto p: Tree[q.first]) {
      if (dp[p.first]<0ll) que.push(P(p.first, q.second+p.second));
    }
  }
}



int main() {
  INCANT;
  cin >> N;
  int a,b;ll c;
  rep(i, N-1) {
    cin >> a >> b >> c;
    a--;b--;
    Tree[a].push_back(P(b,c));
    Tree[b].push_back(P(a,c));
  }
  cin >> Q >> K;
  rep(i, Q) {
    cin >> a >> b;
    a--;b--;
    Ans[i][0]=a;Ans[i][1]=b;
  }
  rep(i, N) dp[i]=-1;
  K--;
  bfs();
  rep(i, Q) {
    cout << dp[Ans[i][0]] + dp[Ans[i][1]] << endl;
  }
  
  return 0;
}