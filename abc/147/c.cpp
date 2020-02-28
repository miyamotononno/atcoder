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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
vector<P> A[16];

bool check(bitset<15> bs) {
  queue<int> que;
  bool searched[N];
  fill(searched, searched+N, false);
  rep(i, N) {
    if (searched[i]) continue;
    if (bs[i]) {
      que.push(i);
      while(!que.empty()) {
        int now = que.front(); que.pop();
        searched[now] = true;
        rep(j, A[now].size()) {
          P p = A[now][j];
          if (p.second) {
            int next = p.first;
            if (!bs[next]) return false;
            if (!searched[next]) que.push(next);
          } else {
            int next = p.first;
            if (bs[next]) return false;
          }
        }
      } 
    }
  }
  return true;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int c;
  rep(i, N) {
    cin >> c;
    rep(j, c) {
      int a,b;
      cin >> a>> b;
      a--;
      A[i].push_back(make_pair(a,b));
    }
  }

  int ans = 0;
  rep(i, 1<<N) {
    bitset<15> bs(i);
    if (check(bs)) {
      int a = bs.count();
      ans = max(ans, a);
    }
  }
  cout << ans << endl;
  
  return 0;
}