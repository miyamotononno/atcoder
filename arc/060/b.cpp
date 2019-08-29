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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N, A;
int B[51];
ll DP[51][5010];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> A;
  int x;
  rep(i, N){
    cin >> x;
    B[i] = A - x;
  }
  DP[0][N*A] = 1ll;
  rep(i, N){
    rep(j, 2*N*A){
      if (DP[i][j]>0){
        DP[i+1][B[i]+j]+=DP[i][j];
        DP[i+1][j]+=DP[i][j];
      }
    }
  }

  cout << DP[N][N*A] -1 << "\n"; // 何も選ばなかった場合をのぞく
  return 0;
}