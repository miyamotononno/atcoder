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
int N;
string s;

// 65-90
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cin >> s;
  char ans[s.size()];

  rep(i, s.size()) {
    int n = s[i]-'0';
    if (n+N<=42) ans[i] = (char)('0'+n+N);
    else {
      int d = n-26+N;
      ans[i] = (char)('0'+d);
    }
  }

  rep(i, s.size()) cout << ans[i];
  cout << endl;
  return 0;
}