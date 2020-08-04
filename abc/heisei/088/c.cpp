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
const int INF = 1000000007;
int C[3][3], B[3];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int sm = 0;
  int a = 0;
  rep(i, 3){
    rep(j, 3){
      cin >> a;
      C[i][j] = a;
      sm += a;
    }
  }
  if (sm%3>0) {
    cout << "No" << endl;
    return 0;
  }
  // a1を固定して考える
  bool flag = false;
  rep(a1, 101){
    rep(i, 3){
      if (C[i][0] - a1 < 0){
        flag = true;
        break;
      }
      B[i] = C[i][0] - a1;
    }
    if (flag) continue;
    int a2 = C[0][1] - B[0];
    if (a2 < 0) continue;
    rep(i, 3){
      if (a2 != C[i][1] - B[i]){
        flag = true;
        break;
      }
    }
    if (flag) continue;
    int a3 = C[0][2] - B[0];
    if (a3 < 0) continue;
    rep(i, 3){
      if (a3 != C[i][2] - B[i]){
        flag = true;
        break;
      }
    }
    if (flag) continue;
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
