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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
vector<int> L;
int DP[2005];
priority_queue<int, vector<int>, greater<int> > que;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N) {
    cin >> a;
    L.push_back(a);
  }
  sort(ALL(L));
  rep(i, N) {
    if (i==0 || i==1) continue;
    rep(j, i-1) {
      que.push(L[j]+L[i-1]);
    }
    int cnt = i-1;
    while(true) {
      if (que.empty()) {
        DP[i] = DP[i-1];
        break;
      }
      int q = que.top();
      if (q<=L[i]) { // qは小さい二つの辺の和
        que.pop();
        cnt--;
      } else {
        DP[i] = DP[i-1] + que.size();
        break;
      }
    }
  }
  cout << DP[N-1] << "\n";
  return 0;
}