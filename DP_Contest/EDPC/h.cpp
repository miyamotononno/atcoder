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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int H, W;
char A[1003][1003];
ll DP[1003][1003];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  rep(i, H){
    rep(j, W) cin >> A[i][j];
  }

  DP[0][0] = 1;

  rep(h, H){
    rep(w, W){
      if (h < H-1 && A[h+1][w] == '.'){
        DP[h+1][w] += DP[h][w];
        DP[h+1][w] %= MOD;
      }
      if (w < W-1 && A[h][w+1] == '.'){
        DP[h][w+1] += DP[h][w];
        DP[h][w+1] %= MOD;
      }
    }
  }

  cout << DP[H-1][W-1] << endl;
  return 0;
}
