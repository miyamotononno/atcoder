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
string S;
set<char> seen;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  if (S.size() < 26) {
    for (char c: S) seen.insert(c);
    for (char c='a';c<='z';c++) {
      if (!seen.count(c)) {
        S+=c;
        cout << S << endl;
        return 0;
      }
    }
  }

  rep_down(i, 26){
    seen.insert(S[i]);
    auto it = seen.upper_bound(S[i]);
    if (it != seen.end()) {
      string res = S.substr(0, i)+*it;
      cout << res << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}