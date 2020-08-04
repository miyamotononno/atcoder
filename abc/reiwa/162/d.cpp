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
string S;
ll r,g,b;

int main() {
  INCANT;
  cin >> N;
  cin >> S;
  rep(i, N) {
    if (S[i]=='R') r++;
    if (S[i]=='G') g++;
    if (S[i]=='B') b++;
  }
  ll ans = r*g*b;
  rep(i, N-2) {
    for (int j=i+1; j<N-1; j++) {
      if (S[i]==S[j]) continue;
      int ng = 2*j-i;
      if (ng>=N) continue;
      if (S[ng]!=S[i] && S[ng]!=S[j]) ans--;
    }
  }

  cout << ans << "\n";

  return 0;
}
