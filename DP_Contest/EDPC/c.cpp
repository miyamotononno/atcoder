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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
struct edge {int a,b,c;}; 
int N;
edge W[100005];
int DP[100005][3]; //日にち, i日目にした活動, i日目までの幸福度の最大値

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a,b,c;
  rep(i, N) {
    cin >> a >> b >> c;
    edge e = {a,b,c};
    W[i] = e;
  }

  rep(i, N) {
    if (i==0) {
      DP[0][0] = W[0].a;
      DP[0][1] = W[0].b;
      DP[0][2] = W[0].c;
      continue;
    }
    DP[i][0] = max(DP[i-1][1]+W[i].a, DP[i-1][2]+W[i].a);
    DP[i][1] = max(DP[i-1][0]+W[i].b, DP[i-1][2]+W[i].b);
    DP[i][2] = max(DP[i-1][0]+W[i].c, DP[i-1][1]+W[i].c);
  }

  int ans = max(DP[N-1][0], DP[N-1][1]);
  ans = max(ans, DP[N-1][2]);
  cout << ans << endl;
  return 0;
}