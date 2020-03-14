#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_itr(it, M) for (auto it = M.begin(); it != M.end(); ++it)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
int cnt;

void dfs(string s, char mx) {
  if (s.length() == n) {
    cnt++;
    cout << s << endl;
  }
  else {
    for (char c = 'a'; c <= mx; c++) {
      dfs(s + c, c == mx ? char(mx + 1) : mx);
    }
  }
}
 
int main() {
  cin >> n;
  dfs("", 'a');
  cout << cnt << endl;
  return 0;
}