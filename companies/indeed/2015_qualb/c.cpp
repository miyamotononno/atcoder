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
int N;
vector<int> G[100005];
int S[100005];
vector<int> ans;

void dijkstra() {
  priority_queue<int, vector<int>, greater<int> > pque;
  pque.push(0);
  while(!pque.empty()) {
    int q = pque.top();pque.pop();
    if (S[q]) continue;
    ans.push_back(q);
    S[q] = 1;
    for (auto p: G[q]) {
      if (!S[p]) pque.push(p);
    }
  }
}
int main() {
  INCANT;
  cin >> N;
  int a,b;
  rep(i, N-1) {
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dijkstra();
  rep(i, N) {
    cout << ans[i]+1;
    if (i<N-1) cout << ' ';
    else cout << endl; 
  }
  return 0;
}