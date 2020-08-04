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
vector<int> Tree[100005];
int dp1[100005], dpN[100005];
typedef pair<int, int> P;

void bfs(int start, int dp[100005]) {
  queue<P> que;
  que.push(P(start, 0));
  while(!que.empty()) {
    P q = que.front();que.pop();
    dp[q.first] = q.second;
    for (auto p: Tree[q.first]) {
      if (dp[p]<0) que.push(P(p, q.second+1));
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
    Tree[a].push_back(b);
    Tree[b].push_back(a);
  }
  rep(i, N) {
    dp1[i]=-1;
    dpN[i]=-1;
  }
  bfs(0, dp1);
  bfs(N-1, dpN);
  bool flag = false;
  int cnt=0;
  rep(i, N) {
    if (dp1[i]<=dpN[i]) cnt++;
  }
  string ans = cnt > N-cnt?"Fennec":"Snuke"; //-1番目の人の勝敗
  cout << ans << "\n";
  return 0;
}