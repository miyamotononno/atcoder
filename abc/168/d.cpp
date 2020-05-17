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
int N, M;
vector<int> G[100005];
int d[100005]; // 最後に全部に1足すこと
typedef pair<int, int> P;

void dijkstra() {
  queue<P> que;
  que.push(P(0, INF));
  while(!que.empty()) {
    P q = que.front(); que.pop();
    if (d[q.first]>0) continue;
    d[q.first] = q.second+1;
    for (auto n: G[q.first]) {
      if (d[n]==0) que.push(P(n, q.first));
    }
  }
}

int main() {
  INCANT;
  cin >> N >> M;
  int a,b;
  rep(i, M) {
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dijkstra();
  cout << "Yes" << endl;
  rep(i, N) {
    if (i==0) continue;
    cout << d[i] << endl;
  }
  return 0;
}