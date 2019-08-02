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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
struct edge {int cost; ll value;}; 
int N, W;
edge L[103];
ll DP[103][100005]; //日にち, i日目までで使った重さ, i日目までの幸福度の最大値

ll dfs(int idx, int w){
  if (idx==N) return 0;
  if (w==0) return 0;
  if (DP[idx][w] > 0) return DP[idx][w];
  edge e = L[idx];
  ll v1 = dfs(idx+1, w);
  if (w < e.cost) {
    DP[idx][w] = v1;
    return v1;
  }
  ll v2 = dfs(idx+1, w-e.cost) + e.value;
  if (v1 > v2) {
    DP[idx][w] = v1;
    return v1;
  }
  DP[idx][w] = v2; 
  return v2;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> W;
  int w; 
  ll v;
  rep(i, N) {
    cin >> w >> v;
    edge e = {w, v};
    L[i] = e;
  }

  DP[0][0] = 0;
  ll ans = dfs(0, W);
  cout << ans << endl;


  return 0;
}