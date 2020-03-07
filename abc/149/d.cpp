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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, K, R, S, P;
string T;

int get_point(char aite) {
  if (aite=='r') return P;
  else if (aite == 's') return R;
  else return S;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  cin >> R >> S >> P;
  cin >> T;
  int ans = 0;
  rep(i, K) {
    int idx = i;
    char now = T[idx];
    int cnt=0;
    while(idx<N) {
      if (now == T[idx]) {
        cnt++;
      }else {
        int z = (cnt+1) /2;
        ans+=get_point(now) *z;
        now = T[idx];
        cnt=1;
      }
      idx+=K;
    }
    int z = (cnt+1) /2;
    ans+=get_point(now) * z;
  }

  cout << ans << "\n";
  return 0;
}