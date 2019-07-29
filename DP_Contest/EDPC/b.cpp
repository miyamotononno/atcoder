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
int N, K;
int H[100005];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N >> K;
  rep(i, N) cin >> H[i];

  vector<int> DP(100005, 1000000007);
  DP[0] = 0;
  rep(i, N) {
    if (i==0) {
      rep(j, K) DP[j+1] =abs(H[j+1] - H[0]); 
      continue;
    }

    rep(j, K) {
      int next = j+i+1;
      DP[next] = min(DP[next], abs(H[next]-H[i])+DP[i]);
    }
  }
  cout << DP[N-1] << endl;
  
  return 0;
}