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
int n;
string S;
int c[100001]; //羊1, 狼0

bool dfs(int idx, int now, int pre) {
  if (idx==n-1  && c[idx] != now) return false;
  if (idx==n) return c[0]==now;
  c[idx] = now;
  if (S[idx]=='o') {
    if (now) return dfs(idx+1, pre, now);
    else return dfs(idx+1, !pre, now);
  } else {
    if (now) return dfs(idx+1, !pre, now);
    else return dfs(idx+1, pre, now);
  }
  return 0;
}

int main() {
  INCANT;
  cin >> n >> S;

  rep(i, 2) {
    rep(j, 2) {
      fill(c, c+n, -1);
      c[0]=j;
      if  (S[0]=='o') c[n-1] = j?i:!i;
      else c[n-1] = j?!i:i;
      if (dfs(1, i, j)) {
        rep(k, n) {
          char a = c[k]?'S':'W';
          cout << a;
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << "\n";
  return 0;
}