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
int n,x;
int h[101], s[101];
vector<int> T[101];
typedef pair<int, int> P;

P dfs(int idx) {
  int npath=0;
  int point=h[idx];
  s[idx] = 1;
  for (auto ne: T[idx]) {
    if (s[ne]<0) {
      P p = dfs(ne);
      if (p.second>0) {
        npath+=p.first;
        point+=p.second;
      }
    }
  }
  if (point>0) return P(npath+1, point);
  return P(1, 0);
}

int main() {
  INCANT;
  cin >> n >> x;
  rep(i, n) cin >> h[i];
  int a,b;
  rep(i, n-1) {
    cin >> a >> b;
    a--;b--;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  fill(s, s+n, -1);
  P p = dfs(x-1);
  cout << 2*(p.first-1) << "\n";
  return 0;
}