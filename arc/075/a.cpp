#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
int s[102];

int main() {
  INCANT;
  cin >> n;
  int ans=0;
  rep(i, n) {
    cin >> s[i];
    ans+=s[i];
  }
  if (ans%10!=0) {
    cout << ans << endl;
    return 0;
  }
  sort(s, s+n);
  
  rep(i, n) {
    if (s[i]%10!=0) {
      cout << ans-s[i] << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}