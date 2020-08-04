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
typedef pair<int, char> P;
int N, M;
vector<P> a;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int s;
  char c;
  rep(i, M) {
    cin >> s >> c;
    s--;
    a.push_back(P(s, c));
  }
  string ans="";
  rep(i, N) ans+='-';
  
  rep(i,M) {
    int d = a[i].first;
    char v = a[i].second;
    if (ans[d]!='-' && ans[d]!=v) {
      cout << -1 << "\n";
      return 0;
    }
    if (d==0 && v=='0') {
      if (N!=1) {
        cout << -1 << "\n";
        return 0;
      }
    }
    ans[d] = v;
  }
  rep(i, N) {
    if (ans[i]=='-') {
      ans[i]=i==0&&N>1?'1':'0';
    }
  }

  cout << ans << "\n";
  return 0;
}