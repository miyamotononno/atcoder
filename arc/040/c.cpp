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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
char s[102][102];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) {
    rep(j, N) cin >> s[i][j];
  }
  int cnt=0;
  rep(i, N) {
    int n_j = -1;
    for (int j=N-1; j>=0; j--) {
      if (s[i][j]=='.') {
        n_j = j;
        cnt++;
        break;
      }
    }
    if (n_j>=0) {
      for (int j=n_j; j<N; j++) s[i+1][j] = 'o';
    }
  }
  cout << cnt << "\n";
  return 0;
}