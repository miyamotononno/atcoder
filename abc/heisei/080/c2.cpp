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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const int INF = 2e9;
int N;
bool F[103][10];
int P[103][10];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) rep(j, 10) cin >> F[i][j];
  rep(i, N) rep(j, 11) cin >> P[i][j];
  
  int ans = -INF;
  rep(bit, 1<<10) {
    int tmp = 0;
    if (bit==0) continue;
    rep(j, N) {
      int cnt=0;
      rep(k, 10) {
        if (F[j][k] && (1<<k & bit)) cnt++; //  その店がやっているかつ自分も営業する
      }
      tmp+=P[j][cnt];
    }
    
    ans=max(tmp, ans);
  }
  cout << ans << "\n";
  return 0;
}