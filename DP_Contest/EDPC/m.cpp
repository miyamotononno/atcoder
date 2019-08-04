#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
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
int N, K;
ll A[101];
ll DP[102][100002]; //i人目, 使ったあめの個数はj
ll reSumMax[101];

// j個のあめをi人に配る場合の数は、
// j-1個のあめをi人に配る場合の数とj個のあめをi-1人に配る場合の数に等しい。

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> A[i];
 
  DP[0][0] = 1LL;
    for (int i = 1; i <= N; i++) {
        DP[i][0] = 1LL;
        for (int j = 1; j <= K; j++) {
            DP[i][j] += DP[i][j - 1] + DP[i - 1][j];
            if (j > A[i]) DP[i][j] -= DP[i - 1][j - A[i] - 1];
            DP[i][j] = (DP[i][j] + MOD) % MOD;
        }
    }
 
  cout << DP[N][K] << endl;
  return 0;
}