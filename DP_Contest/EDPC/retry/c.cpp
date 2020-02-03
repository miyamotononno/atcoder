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
using namespace std;
int N;
int A[100003], B[100003], C[100003];
int H[100004][3]; // happiness // n日目にA, B, Cをした

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) {
    cin >> A[i] >> B[i] >> C[i];
  }
  // 概念としての0日目を設ける。1-N日目が実際の活動とする。
  rep(i, N) {
    rep(j, 3) {
      H[i+1][1] = max(H[i][0]+B[i], H[i+1][1]);
      H[i+1][2] = max(H[i][0]+C[i], H[i+1][2]);
      H[i+1][0] = max(H[i][1]+A[i], H[i+1][0]);
      H[i+1][2] = max(H[i][1]+C[i], H[i+1][2]);
      H[i+1][0] = max(H[i][2]+A[i], H[i+1][0]);
      H[i+1][1] = max(H[i][2]+B[i], H[i+1][1]);
    }
  }
  int ans = max(H[N][0], max(H[N][1], H[N][2]));
  cout << ans << "\n";
  return 0;
}