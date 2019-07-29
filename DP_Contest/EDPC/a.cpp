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
int N;
int H[100005];
int DP[100005];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  rep(i, N) cin >> H[i];

  rep(i, N) {
    if (i==0) {
      DP[0] = H[0]; // N=1のときはないので。
      continue;
    };
    if (i==1) {
      DP[1] = abs(H[1] - H[0]);
      continue;
    }
    if (i==2) {
      DP[i] = min(abs(H[i] - H[i-1])+DP[i-1], abs(H[i] - H[i-2]));
      continue;
    }
    DP[i] = min(abs(H[i] - H[i-1])+DP[i-1], abs(H[i] - H[i-2])+DP[i-2]);
  }

  cout << DP[N-1] << endl;
  return 0;
}